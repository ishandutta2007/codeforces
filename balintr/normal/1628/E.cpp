#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

template <typename T, int MSZ>
struct RMQ {
    using funType = const T& (*)(const T&, const T&);
    funType merge = max;
    T table[lg2(MSZ)][MSZ];
    int sz, height;

    void init(int inSz){
        sz = inSz;
        height = lg2(sz);
        for (int k = 1, pw = 1; k < height; ++k, pw *= 2) {
            int len = sz - pw*2 + 1;
            for (int j = 0; j < len; ++j) {
                table[k][j] = merge(table[k-1][j], table[k-1][j+pw]);
            }
        }
    }

    // Min of [l, r)
    T query(int l, int r){
        assert(l < r);
        int k = lg2(r-l) - 1;
        return merge(table[k][l], table[k][r - (1 << k)]);
    }

    // Access the bottom row of the sparse table
    inline T& operator[](int i){
        return table[0][i];
    }
};

struct Node {
    int mn, mx, mnV, mxV, lazy;
};

Node newNode(int v){
    return {v, v, INF, -1, -1};
}

Node merge(Node a, Node b){
    return {min(a.mn, b.mn), max(a.mx, b.mx), min(a.mnV, b.mnV), max(a.mxV, b.mxV), -1};
}

#ifdef WIN32
const int MN = 1005;
const int TSZ = 1 << 10;
#else
const int MN = 3e5 + 5;
const int TSZ = 1 << 19;
#endif
int n, q;
pair<int, pii> edges[MN];
int dsu[MN];
int other[MN];
pii nxt[MN]; // linked list of line tree
int ind[MN]; // index of each node in line tree
int revInd[MN];
int arr[MN];
RMQ<int, MN> rmq;
Node tree[TSZ*2];

int find(int a){
    return dsu[a] == a ? a : dsu[a] = find(dsu[a]);
}

void buildLineTree(){
    sort(edges, edges + n-1);
    ms(nxt, -1);
    for (int i = 0; i < n; i++) {
        dsu[i] = other[i] = i;
    }
    for (int i = 0; i < n-1; i++) {
        auto [a, b] = edges[i].sn;
        a = find(a);
        b = find(b);
        dsu[b] = a;
        nxt[other[a]] = {b, edges[i].fs};
        other[a] = other[b];
    }
    int n1 = find(0);
    for (int i = 0; i < n-1; i++) {
        ind[n1] = i;
        revInd[i] = n1;
        arr[i] = nxt[n1].sn;
        n1 = nxt[n1].fs;
    }
    ind[n1] = n-1;
    revInd[n-1] = n1;
}

Node build(int i, int segL, int segR){
    if(segL + 1 == segR) return tree[i] = newNode(ind[segL]);
    int mid = (segL + segR)/2;
    return tree[i] = merge(build(i*2, segL, mid), build(i*2+1, mid, segR));
}

void pushDown(int i){
    int lzy = tree[i].lazy;
    tree[i].lazy = -1;
    if(lzy == -1) return;

    if(lzy == 1){
        tree[i*2].mnV = tree[i*2].mn;
        tree[i*2].mxV = tree[i*2].mx;
        tree[i*2+1].mnV = tree[i*2+1].mn;
        tree[i*2+1].mxV = tree[i*2+1].mx;
    }
    else {
        tree[i*2].mnV = tree[i*2+1].mnV = INF;
        tree[i*2].mxV = tree[i*2+1].mxV = -1;
    }
    tree[i*2].lazy = tree[i*2+1].lazy = lzy;
}

Node update(int i, int segL, int segR, int l, int r, int v){
    if(r <= segL || l >= segR) return tree[i];
    if(l <= segL && r >= segR){
        tree[i].lazy = v;
        if(v){
            tree[i].mnV = tree[i].mn;
            tree[i].mxV = tree[i].mx;
        }
        else {
            tree[i].mnV = INF;
            tree[i].mxV = -1;
        }
        return tree[i];
    }
    pushDown(i);
    int mid = (segL + segR)/2;
    return tree[i] = merge(update(i*2, segL, mid, l, r, v), update(i*2+1, mid, segR, l, r, v));
}

int main(){
    boost();
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = {c, {a, b}};
    }
    buildLineTree();
    build(1, 0, n);

    for (int i = 0; i < n-1; i++) {
        rmq[i] = arr[i];
    }
    rmq.init(n-1);

    /*for (int i = 0; i < n; i++) printf("%2d%c", ind[i], " \n"[i == n-1]);
    for (int i = 0; i < n; i++) printf("%2d%c", revInd[i], " \n"[i == n-1]);
    printf(" ");
    for (int i = 0; i < n-1; i++) printf(" %2d", arr[i]);
    printf("\n");
    fflush(stdout);*/

    while(q--){
        int t;
        cin >> t;

        if(t == 1 || t == 2){
            int l, r;
            cin >> l >> r;
            l--;
            update(1, 0, n, l, r, t & 1);
            //cout << "mnV " << tree[1].mnV << endl;
            //cout << "mxV " << tree[1].mxV << endl;
        }
        else {
            int x; cin >> x; x--;
            x = ind[x];
            int mn = tree[1].mnV;
            int mx = tree[1].mxV;

            int ans = -1;
            if(mn < x) ans = max(ans, rmq.query(mn, x));
            if(x < mx) ans = max(ans, rmq.query(x, mx));

            cout << ans << '\n';
        }
    }
}
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
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

template <typename T, int MSZ>
struct RMQ {
    using funType = const T& (*)(const T&, const T&);
    funType merge = min;
    T table[__lg(MSZ)+1][MSZ];
    int sz, height;

    void init(int inSz){
        sz = inSz;
        height = __lg(sz)+1;
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
        int k = __lg(r-l);
        return merge(table[k][l], table[k][r - (1 << k)]);
    }

    // Access the bottom row of the sparse table
    inline T& operator[](int i){
        return table[0][i];
    }
};

template <int MSZ>
struct LCA {
    int sz;
    vi *adjList;
    int tc = 0, ind = 0;
    int time[MSZ], path[MSZ-1];
    RMQ<int, MSZ-1> rmq;

    void init(int inSz, vi *inAdjList){
        init(inSz, inAdjList, 0);
    }

    void init(int inSz, vi *inAdjList, int src){
        sz = inSz;
        adjList = inAdjList;
        dfs(src, -1);
        rmq.init(sz-1);
    }

    void dfs(int n1, int par){
        time[n1] = tc++;
        for (int n2 : adjList[n1]){
            if (n2 == par) continue;
            path[ind] = n1;
            rmq[ind++] = time[n1];
            dfs(n2, n1);
        }
    }

    int operator()(int a, int b){
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};

const int H = 17;
const int MN = 1e5 + 5;
const int ME = 2e5 + 5;
int n, m;
int dsu[MN];
pii edges[ME];
vi adjList[MN];
int dep[MN], par[MN], anc[MN][H];
int arr[MN];
LCA<MN> lca;

int find(int a){
    return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
}

void dfs(int n1){
    anc[n1][0] = par[n1];
    if(par[n1] != -1) FOR(i, 1, H){
        int n2 = anc[anc[n1][i-1]][i-1];
        if(n2 == -1) break;
        anc[n1][i] = n2;
    }

    for(int n2 : adjList[n1]){
        if(n2 == par[n1]) continue;
        par[n2] = n1;
        dep[n2] = dep[n1] + 1;
        dfs(n2);
    }
}

int getDep(int n1, int k){
    FORR(i, H-1, 0){
        if(dep[n1] - (1<<i) < k) continue;
        n1 = anc[n1][i];
    }
    assert(dep[n1] == k);
    return n1;
}

void dfs1(int n1){
    for(int n2 : adjList[n1]){
        if(n2 == par[n1]) continue;
        arr[n2] += arr[n1];
        dfs1(n2);
    }
}

int main(){
    boost();
    cin >> n >> m;

    ms(dsu, -1);
    FR(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[i] = {a, b};
        int fa = find(a);
        int fb = find(b);
        if(fa != fb){
            dsu[fa] = fb;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }
    }

    par[0] = -1;
    ms(anc, -1);
    dfs(0);
    lca.init(n, adjList);

    FR(i, m){
        auto [a, b] = edges[i];
        if(par[a] == b || par[b] == a) continue;
        int l = lca(a, b);

        if(a == l) swap(a, b);
        if(b == l){
            int below = getDep(a, dep[b]+1);
            arr[below]++;
            arr[a]--;
        }
        else {
            arr[0]++;
            arr[a]--;
            arr[b]--;
        }
    }

    dfs1(0);

    FR(i, n) cout << !arr[i];
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 2e5 + 5;
int n, q;
int a1[MN], a2[MN];
int arr[MN];

struct Node {
    ll sum, mx, mn;
    ll lmx, rmx, tmx;
};

struct SegTree {
    Node data[MN*2];

    inline Node merge(Node t1, Node t2){
        Node res = Node{t1.sum + t2.sum, max(t1.mx, t2.mx), min(t1.mn, t2.mn)};
        res.lmx = max(t1.lmx, t1.sum + t2.lmx);
        res.rmx = max(t2.rmx, t2.sum + t1.rmx);
        res.tmx = max(max(t1.tmx, t2.tmx), t1.rmx + t2.lmx);
        return res;
    }

    void build(){
        for (int i = n-1; i > 0; --i){
            data[i] = merge(data[i*2], data[i*2+1]);
        }
    }

    vector<Node> lNodes, rNodes;
    // Query range [l, r)
    Node query(int l, int r){
        lNodes.clear();
        rNodes.clear();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) lNodes.pb(data[l++]);
            if(r&1) rNodes.pb(data[--r]);
        }
        for (int i = rNodes.size()-1; i >= 0; --i) {
            lNodes.pb(rNodes[i]);
        }

        Node res = lNodes[0];
        for (int i = 1; i < lNodes.size(); ++i) {
            res = merge(res, lNodes[i]);
        }
        return res;
    }

    // Access the last layer of the segment tree
    inline Node& operator[](int i){
        return data[i + n];
    }
};

SegTree tree;

int main(){
    boost();
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a2[i];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = a2[i] - a1[i];
    }
    for (int i = 0; i < n; ++i) {
        tree[i] = {arr[i], arr[i], arr[i], max(0, arr[i]), max(0, arr[i]), max(0, arr[i])};
    }

    tree.build();

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;

        Node qRes = tree.query(l, r);
        if(qRes.sum != 0 || qRes.rmx != 0){
            cout << "-1\n";
            continue;
        }
        cout << qRes.tmx << '\n';
    }
}
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

template<typename T, int MSZ>
struct SegTree {
    T data[MSZ*2];
    int sz;
    static constexpr T unit = 0;

    inline T merge(T t1, T t2){
        return max(t1, t2);
    }

    void init(int inSz){
        sz = inSz;
        FR(i, sz*2) data[i] = 0;
    }

    void build(){
        for (int i = sz-1; i > 0; --i){
            data[i] = merge(data[i*2], data[i*2+1]);
        }
    }

    // Increase value at position p by v
    void update(int p, T v){
        //cerr << "upd " << p << " " << v << endl;
        for (data[p += sz] += v; p >>= 1;){
            data[p] = merge(data[p*2], data[p*2+1]);
        }
    }

    // Query range [l, r)
    T query(int l, int r){
        T resL = unit, resR = unit;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if(l&1) resL = merge(resL, data[l++]);
            if(r&1) resR = merge(data[--r], resR);
        }
        return merge(resL, resR);
    }

    // Access the last layer of the segment tree
    inline T& operator[](int i){
        return data[i + sz];
    }
};

const int MN = 2e5 + 5;
const int TSZ = 1e6;
int n, q;
int arr[MN];
SegTree<ll, TSZ> tree;

void solve(){
    cin >> n >> q;
    vi facts;
    for(int i = 1; i*i <= n; i++) if(n % i == 0) facts.pb(i), facts.pb(n/i);
    UNIQUE(facts);
    facts.pop_back();

    int m = SZ(facts);
    vi offs(m+1);
    FR(i, m) offs[i+1] = offs[i] + facts[i];
    tree.init(offs.back());

    FR(i, n){
        int a; cin >> a;
        arr[i] = a;

        FR(j, m){
            int f = facts[j];
            tree[offs[j] + (i % f)] += (ll) a * f;
        }
    }

    tree.build();

    cout << tree.query(0, offs.back()) << '\n';
    while(q--){
        int p, v;
        cin >> p >> v;
        p--;
        int dif = v - arr[p];
        arr[p] = v;

        FR(j, m){
            int f = facts[j];
            tree.update(offs[j] + (p % f), (ll) dif * f);
        }

        cout << tree.query(0, offs.back()) << '\n';
    }
}

int main(){
    boost();
    int t; cin >> t;
    while(t--) solve();
}
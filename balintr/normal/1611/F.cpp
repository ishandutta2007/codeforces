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


template<typename T, int MSZ>
struct SegTree {
    T data[MSZ*2];
    int sz;
    static constexpr T unit = INF;

    inline T merge(T t1, T t2){
        return min(t1, t2);
    }

    void init(int inSz){
        sz = inSz;
    }

    void build(){
        for (int i = sz-1; i > 0; --i){
            data[i] = merge(data[i*2], data[i*2+1]);
        }
    }

    // Set value at position p to v
    void update(int p, T v){
        for (data[p += sz] = v; p >>= 1;){
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
int t, n, p;
int arr[MN];
SegTree<int, MN> tree;

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> p;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        pii best = {0, 0};

        ll offs = 0;
        vector<ll> compr;
        for (int i = n-1; i >= 0; i--) {
            compr.pb(-offs);
            offs += arr[i];
        }
        UNIQUE(compr);

        tree.init(SZ(compr));
        offs = 0;
        for (int i = n-1; i >= 0; i--) {
            tree.update(lbv(compr, -offs), i);
            offs += arr[i];
            int qRes = tree.query(0, lbv(compr, -p - offs));
            if(qRes == INF) qRes = n;
            best = max(best, {qRes - i, i});
        }
        for (int i = 0; i < SZ(compr); i++) {
            tree.update(i, INF);
        }

        if(best.fs == 0) cout << "-1\n";
        else cout << best.sn+1 << ' ' << best.sn+best.fs << '\n';
    }
}
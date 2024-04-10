#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
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

    void reset(){
        for (int i = 0; i < sz; ++i) {
            update(i, unit);
        }
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
int t, n;
int arr[MN];
SegTree<int, MN> tree;
int nextBig[MN];
int rBound[MN];
vi vals;

int compr(int x){
    return lower_bound(ALL(vals), x) - vals.begin();
}

int main(){
    boost();
    cin >> t;
    while(t--){
        vals.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            vals.pb(arr[i]);
        }
        UNIQUE(vals);
        tree.reset();
        tree.init(vals.size());
        tree.reset();

        for (int i = n-1; i >= 0; --i) {
            nextBig[i] = min(n, tree.query(compr(arr[i]), vals.size()));
            tree.update(compr(arr[i]), i);
        }
        tree.reset();
        for (int i = n-1; i >= 0; --i) {
            rBound[i] = min(n, tree.query(compr(arr[i]), vals.size()));
            tree.update(compr(arr[i]), min(n, nextBig[i]));
        }
        tree.reset();

        for (int i = n-1; i >= 0; --i) {
            nextBig[i] = min(n, tree.query(0, compr(arr[i])+1));
            tree.update(compr(arr[i]), i);
        }
        tree.reset();
        for (int i = n-1; i >= 0; --i) {
            rBound[i] = min(rBound[i], tree.query(0, compr(arr[i])+1));
            if(i < n-1) rBound[i] = min(rBound[i], rBound[i+1]);
            tree.update(compr(arr[i]), min(n, nextBig[i]));
        }
        tree.reset();


        ll total = 0;
        for (int i = 0; i < n; ++i) {
            total += rBound[i] - i;
        }
        cout << total << '\n';
    }
}
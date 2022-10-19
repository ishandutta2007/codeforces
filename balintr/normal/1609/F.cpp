#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"

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

#define gc (*_ii++)
#define readBuf() assert(fread(_buf, 1, IO_SZ, stdin) < IO_SZ)
const int IO_SZ = 20 << 20;
char _buf[IO_SZ], *_ii = _buf, _;
template <typename T> inline void scan(T &x){while((x=gc)<=' '); for(x-='0'; (_=gc)>='0'; x=x*10+_-'0');}

template <typename T, int MSZ>
struct RangeBIT {
    int sz;
    T tree[MSZ+1], pop[MSZ+1], popc;

    void init(int inSz){
        sz = inSz;
    }

    // Add x to every elem in prefix [0, p]
    inline void update(int p, T x){
        for (int i = ++p; i <= sz; i += i & -i){
            tree[i] += x * p;
            pop[i] += x;
        }
        popc += x;
    }

    // Sum of [0, p]
    inline T query(int p){
        T res = 0, numAfter = popc;
        for (int i = ++p; i > 0; i -= i & -i){
            res += tree[i];
            numAfter -= pop[i];
        }
        return res + numAfter * p;
    }
};

struct Query {
    char type, val;
    int t, l, r;

    const inline bool operator<(const Query &o) const {
        return t < o.t;
    }
};

const int MN = 1e6 + 5;
int n;
ll arr[MN], stk[MN];
int sti;
RangeBIT<ll, MN> tree;
RangeBIT<int, MN> pop;
Query queries[MN*4];
pair<pii, pii> cutoffs[MN];

int main(){
    readBuf();
    scan(n);
    for (int i = 0; i < n; i++) scan(arr[i]);

    for (int i = 0; i < n; i++) {
        while(sti && arr[i] < arr[stk[sti]]) cutoffs[stk[sti--]].fs.sn = i;
        cutoffs[i].fs.fs = sti ? stk[sti]+1 : 0;
        stk[++sti] = i;
    }
    while(sti) cutoffs[stk[sti--]].fs.sn = n;

    for (int i = 0; i < n; i++) {
        while(sti && arr[i] > arr[stk[sti]]) cutoffs[stk[sti--]].sn.sn = i;
        cutoffs[i].sn.fs = sti ? stk[sti]+1 : 0;
        stk[++sti] = i;
    }
    while(sti) cutoffs[stk[sti--]].sn.sn = n;

    for (int i = 0; i < n; i++) {
        int p = popcount(ull(arr[i]));
        queries[i*4] = {0, -1, cutoffs[i].fs.fs-1 + MN*p, i, cutoffs[i].fs.sn};
        queries[i*4+1] = {0, 1, i + MN*p, i, cutoffs[i].fs.sn};
        queries[i*4+2] = {1, -1, cutoffs[i].sn.fs-1 + MN*p, i, cutoffs[i].sn.sn};
        queries[i*4+3] = {1, 1, i + MN*p, i, cutoffs[i].sn.sn};
    }

    tree.init(n+3);
    pop.init(n+3);

    ll total = 0;
    sort(queries, queries + n*4);
    for (int i = 0; i < n*4; i++) {
        Query query = queries[i];
        if(query.type == 0){
            tree.update(query.r, query.t * query.val);
            tree.update(query.l, -query.t * query.val);
            pop.update(query.r, -query.val);
            pop.update(query.l, query.val);
        }
        else {
            total += query.val * tree.query(query.r);
            total -= query.val * tree.query(query.l);
            total += (ll) query.val * pop.query(query.r) * query.t;
            total -= (ll) query.val * pop.query(query.l) * query.t;
        }
    }
    printf("%lld\n", total);
}
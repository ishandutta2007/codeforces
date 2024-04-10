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
// Num used bits
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);}
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);}

template <typename T, int MSZ>
struct RMQ {
    using funType = const T& (*)(const T&, const T&);
    funType merge = min;
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

    int lca(int a, int b){
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};

const int MOD = 1e9 + 7;
const int MN = 205;
int n;
vi adjList[MN];
int dist[MN];
pll preCalc[MN][MN]; // [i][j] is chance that i comes first. Form is first/2^second

void dfs(int n1, int par){
    for(int n2 : adjList[n1]){
        if(par == n2) continue;
        dist[n2] = dist[n1] + 1;
        dfs(n2, n1);
    }
}

ll lshift(ll a, ll b){
    a %= MOD;
    while(b > 30){
        a = (a << 30) % MOD;
        b -= 30;
    }
    return (a << b) % MOD;
}

ll fpow(ll a, ll b){
    ll res = 1;
    ll pw2 = a;
    while(b){
        if(b & 1) res = (res * pw2) % MOD;
        pw2 = (pw2 * pw2) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    boost();
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    for (int i = 1; i < n; ++i) {
        preCalc[i][0] = {0, 0};
        preCalc[0][i] = {1, 0};
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            pll ch1 = preCalc[i-1][j];
            pll ch2 = preCalc[i][j-1];
            ch1.sn++; ch2.sn++;
            if(ch1.sn < ch2.sn) ch1.fs = lshift(ch1.fs, ch2.sn - ch1.sn);
            if(ch2.sn < ch1.sn) ch2.fs = lshift(ch2.fs, ch1.sn - ch2.sn);
            preCalc[i][j] = {(ch1.fs + ch2.fs) % MOD, max(ch1.sn, ch2.sn)};
        }
    }

    ll finalDenom = lshift(1, n) * n % MOD;
    ll finalNum = 0;
    for (int src = 0; src < n; ++src) {
        ll tmpNum = 0;
        dist[src] = 0;
        dfs(src, -1);

        LCA<MN> lca;
        lca.init(n, adjList, src);

        for (int a = 1; a < n; ++a) {
            for (int b = 0; b < a; ++b) {
                int l = lca.lca(a, b);
                pll chance = preCalc[dist[a] - dist[l]][dist[b] - dist[l]]; // Chance that a comes first in the array
                tmpNum += lshift(chance.fs, n - chance.sn);
                tmpNum %= MOD;
            }
        }

        finalNum += tmpNum;
        finalNum %= MOD;
    }

    cout << finalNum * fpow(finalDenom, MOD - 2) % MOD << '\n';
}
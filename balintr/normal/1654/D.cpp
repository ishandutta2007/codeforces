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

const int MOD = 998244353;
const int MN = 2e5 + 5;

namespace Mod {
    ll fact[MN];

    void initFact(){
        fact[0] = 1;
        for (int i = 1; i < MN; ++i) {
            fact[i] = fact[i-1] * i % MOD;
        }
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

    inline ll modInv(ll a){
        return fpow(a, MOD - 2);
    }

    inline ll choose(ll a, ll b){
        return fact[a] * modInv(fact[b]) % MOD * modInv(fact[a - b]) % MOD;
    }
}
using namespace Mod;

vi primes[MN];
int t, n;
vector<pair<int, pii>> adjList[MN];
map<int, int> mp[MN];
ll ans;

void dfs(int n1, int par){
    for(auto [n2, w] : adjList[n1]){
        if(n2 == par) continue;
        dfs(n2, n1);

        for(int a : primes[w.fs]) mp[n2][a]++;
        for(int a : primes[w.sn]){
            int &ref = mp[n2][a];
            if(ref) ref--;
        }

        if(SZ(mp[n2]) > SZ(mp[n1])) swap(mp[n1], mp[n2]);
        for(auto [a, b] : mp[n2]){
            mp[n1][a] = max(mp[n1][a], b);
        }
    }

    /*cout << n1+1 << '\n';
    for(auto [a, b] : mp[n1]) cout << a << '_' << b << ' ';
    cout << endl;*/
}

void dfs1(int n1, int par, ll v){
    ans += v;
    for(auto [n2, w] : adjList[n1]){
        if(n2 == par) continue;
        ll v2 = v * w.sn % MOD * modInv(w.fs) % MOD;
        dfs1(n2, n1, v2);
    }
}

int main(){
    boost();
    for(int i = 2; i < MN; i++){
        int x = i;
        for(int j = 2; j*j <= x; j++){
            while(x % j == 0) x /= j, primes[i].pb(j);
        }
        if(x > 1) primes[i].pb(x);
    }

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n-1; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--; b--;
            /*int g = gcd(c, d);
            c /= g;
            d /= g;*/
            adjList[a].pb({b, {c, d}});
            adjList[b].pb({a, {d, c}});
        }

        dfs(0, -1);
        ll v0 = 1;
        for(auto [a, b] : mp[0]){
            while(b--) v0 = v0 * a % MOD;
        }
        ans = 0;
        dfs1(0, -1, v0);
        cout << ans % MOD << '\n';

        for (int i = 0; i < n; i++) {
            adjList[i].clear();
            mp[i].clear();
        }
    }
}
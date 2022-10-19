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
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

const int MOD = 998244353;
const int MN = 3e5 + 5;

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

int t, n;
int dp1[MN], dp2[MN], pws[MN];

ll solve(){
    cin >> n;
    ll ans = 0;
    FR(dc, n/4+1){
        int remSpace = n - dc*4;
        assert(remSpace >= 0);
        ll v = (ll) dp2[dc*2] * pws[dc] % MOD;
        v = v * choose(remSpace+dc*2, dc*2) % MOD;
        v = v * dp1[remSpace] % MOD;
        ans += v;
    }
    return ans % MOD;
}

int main(){
    boost();

    dp1[0] = dp1[1] = 1;
    FOR(i, 2, MN) dp1[i] = (dp1[i-1] + (ll) dp1[i-2]*(i-1)) % MOD;
    dp2[0] = 1;
    FOR(i, 2, MN) dp2[i] = (ll) dp2[i-2]*(i-1) % MOD;
    pws[0] = 1;
    FOR(i, 1, MN) pws[i] = pws[i-1] * 2 % MOD;
    initFact();

    cin >> t;
    while(t--){
        cout << solve() % MOD << '\n';
    }
}
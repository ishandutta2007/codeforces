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

const int MOD = 1e9 + 7;
const int MN = 1e6 + 5;

namespace Mod {
    ll fact[MN];

    void initFact(){
        fact[0] = 1;
        for (int i = 1; i < MN; ++i) {
            fact[i] = fact[i-1] * i % MOD;
        }
    }

    constexpr ll fpow(ll a, ll b){
        ll res = 1;
        ll pw2 = a;
        while(b){
            if(b & 1) res = (res * pw2) % MOD;
            pw2 = (pw2 * pw2) % MOD;
            b >>= 1;
        }
        return res;
    }

    constexpr ll modInv(ll a){
        return fpow(a, MOD - 2);
    }

    inline ll choose(ll a, ll b){
        return fact[a] * modInv(fact[b]) % MOD * modInv(fact[a - b]) % MOD;
    }
}
using namespace Mod;

int t, n, m, k;
ll pw2s[MN];

void solve(){
    cin >> n >> m >> k;
    ll sum = 0;
    ll pref = 0;
    for (int i = 1; i <= m; i++) {
        int dx = (n - i);
        int dy = (m - i);
        ll mult = (i*pw2s[i-1] - pref) % MOD;
        ll dSum = choose(dx, dy) * mult % MOD;
        pref += mult;
        //cout << dSum << '\n';
        sum += dSum;
        sum %= MOD;
    }
    if(sum < 0) sum += MOD;
    //cout << sum << endl;
    cout << (sum * modInv(fpow(2, n-1)) % MOD * k % MOD) << '\n';
}

int main(){
    initFact();
    pw2s[0] = 1;
    for (int i = 1; i < MN; i++) {
        pw2s[i] = pw2s[i-1] * 2 % MOD;
    }

    boost();
    cin >> t;
    while(t--){
        solve();
    }
}
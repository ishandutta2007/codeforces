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
const int MN = 2e5 + 5, B = 30;
int arr[B][MN];
int t, n, m;

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

int main(){
    boost();
    initFact();

    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = 0; j < 30; j++) {
                if(((x >> j) & 1) == 0) arr[j][l]++, arr[j][r+1]--;
            }
        }
        ll ans = 0;
        for (int i = 0; i < B; i++) {
            int num0s = 0;
            for (int j = 1; j <= n; j++) {
                arr[i][j] += arr[i][j-1];
                num0s += (bool) arr[i][j];
            }
            fill(arr[i], arr[i] + n+2, 0);
            int num1s = n-num0s;
            ll v = 0;
            for (int j = 1; j <= num1s; j += 2) {
                v += choose(num1s, j);
                v %= MOD;
            }
            for (int j = 0; j < num0s + i; j++) {
                v = v*2 % MOD;
            }
            ans += v;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}
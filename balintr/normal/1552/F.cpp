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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const ll MOD = 998244353;
const int MN = 2e5 + 5;
int n;
pair<pii, bool> portals[MN];
ll dp[MN];
ll pref[MN];

int main(){
    //cout << 2000000000LL % MOD << '\n';

    boost();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, s;
        cin >> x >> y >> s;
        portals[i] = {{x, y}, s};
    }

    for (int i = 0; i < n; ++i) {
        int x = portals[i].fs.fs;
        int y = portals[i].fs.sn;
        int prv = lower_bound(portals, portals + n, pair<pii, bool>{{y, 0}, 0}) - portals;
        dp[i] = x - y;
        if(i > 0){
            dp[i] += pref[i-1];
            if(prv > 0){
                dp[i] -= pref[prv-1];
            }
        }
        dp[i] += MOD;
        pref[i] = pref[i-1] + dp[i];
        dp[i] %= MOD;
        pref[i] %= MOD;
    }

    ll total = portals[n-1].fs.fs + 1;
    for (int i = 0; i < n; ++i) {
        if(portals[i].sn){
            total += dp[i];
            total %= MOD;
        }
    }

    /*ll total1 = 0;
    for(int a = 0; a < portals[n-1].fs.fs + 1;){
        a++;
        total1++;
        auto portal = lower_bound(portals, portals + n, pair<pii, bool>{{a, 0}, 0});
        if(portal->fs.fs == a){
            if(portal->sn) a = portal->fs.sn;
            portal->sn ^= 1;
        }
    }*/

    cout << total % MOD << '\n';
}
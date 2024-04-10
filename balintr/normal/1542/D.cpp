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

const ll MOD = 998244353;
const int MN = 505;
int n;
int arr[MN];
ll dp[MN];

int main(){
    boost();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char ch; cin >> ch;
        if(ch == '-') arr[i] = -1;
        else {
            int x; cin >> x;
            arr[i] = x;
        }
    }

    ll total = 0;
    for (int i = 0; i < n; ++i) {
        if(arr[i] == -1) continue;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int j = 0; j < i; ++j) {
            if(arr[j] == -1){
                dp[0] += dp[0] + dp[1];
                dp[0] %= MOD;
                for (int k = 1; k <= n; ++k) {
                    dp[k] += dp[k+1];
                    dp[k] %= MOD;
                }
            }
            else if(arr[j] <= arr[i]){
                for (int k = n; k > 0; --k) {
                    dp[k] += dp[k-1];
                    dp[k] %= MOD;
                }
            }
            else {
                for (int k = 0; k <= n; ++k) {
                    dp[k] += dp[k];
                    dp[k] %= MOD;
                }
            }
        }

        for (int j = i+1; j < n; ++j) {
            if(arr[j] == -1){
                for (int k = 0; k <= n; ++k) {
                    dp[k] += dp[k+1];
                    dp[k] %= MOD;
                }
            }
            else if(arr[j] < arr[i]){
                for (int k = n; k > 0; --k) {
                    dp[k] += dp[k-1];
                    dp[k] %= MOD;
                }
            }
            else {
                for (int k = 0; k <= n; ++k) {
                    dp[k] += dp[k];
                    dp[k] %= MOD;
                }
            }
        }

        ll sum = 0;
        for (int j = 0; j <= n; ++j) {
            sum += dp[j];
            sum %= MOD;
        }
        total = (total + arr[i] * sum) % MOD;
    }
    cout << total << '\n';
}
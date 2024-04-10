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

const int MN = 1e6 + 6;
int t, n, e;
int arr[MN];
int dp[MN][2];
bitset<MN> prime;

int main(){
    prime.flip();
    for (int i = 2; i < MN; i++) {
        for(int j = i+i; j < MN; j += i) prime[j] = false;
    }

    boost();
    cin >> t;
    while(t--){
        cin >> n >> e;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            dp[i][0] = dp[i][1] = 0;
        }
        ll ans = 0;
        for (int i = n-1; i >= 0; i--) {
            if(arr[i] == 1){
                dp[i][0] = 1;
                if(i + e < n){
                    dp[i][0] += dp[i+e][0];
                    dp[i][1] += dp[i+e][1];
                }
                ans += dp[i][1];
            }
            else if(prime[arr[i]]){
                dp[i][1] = 1;
                if(i + e < n) dp[i][1] += dp[i+e][0];
                ans += dp[i][1] - 1;
            }
        }
        cout << ans << '\n';
    }
}
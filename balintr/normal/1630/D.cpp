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

const int MN = 1e6 + 5;
int t, n, m, k;
int arr[MN];
bool state[MN];
int mn[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += abs(arr[i]);
        }
        k = 0;
        for (int i = 0; i < m; i++) {
            int a; cin >> a;
            k = gcd(k, a);
        }

        fill(state, state + k, 0);
        fill(mn, mn + k, INF);
        for (int i = 0; i < n; i++) {
            state[i%k] ^= arr[i] < 0;
            mn[i%k] = min(mn[i%k], abs(arr[i]));
        }

        ll s1 = 0, s2 = 0;
        for (int i = 0; i < k; i++) {
            if(state[i]) s1 += mn[i];
            else s2 += mn[i];
        }

        ll ans = sum - 2*min(s1, s2);
        cout << ans << '\n';
    }
}
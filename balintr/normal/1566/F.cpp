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
#define pb push_back
#define eb emplace_back
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

const int MN = 2e5 + 5;
int t, n, m;
int arr[MN];
set<pii> segs[MN];
ll dp[2][MN]; // [0] = ends on left, [1] = ends on right

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i <= n; ++i) {
            segs[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            int li = lower_bound(arr, arr + n, l) - arr;
            int ri = upper_bound(arr, arr + n, r) - arr;
            if(li != ri) continue;
            assert(li <= n);
            segs[li].insert({l, r});
        }

        dp[0][0] = 0;
        for(auto [l, r] : segs[0]){
            dp[0][0] = max(dp[0][0], (ll) arr[0] - r);
        }
        dp[1][0] = dp[0][0]*2;

        for (int i = 1; i < n; ++i) {
            set<pii> stl, str;
            for(auto [l, r] : segs[i]){
                stl.insert({l, r});
                str.insert({r, l});
            }

            ll lc = stl.empty() ? 0 : stl.rbegin()->fs - arr[i-1];
            ll lmn = min(dp[0][i-1] + lc*2, dp[1][i-1] + lc);
            ll rc = 0;
            dp[0][i] = lmn + rc;
            dp[1][i] = lmn + rc*2;

            auto iter = str.rbegin();
            while(iter != str.rend()){
                stl.erase({iter->sn, iter->fs});
                lc = stl.empty() ? 0 : stl.rbegin()->fs - arr[i-1];
                lmn = min(dp[0][i-1] + lc*2, dp[1][i-1] + lc);
                rc = arr[i] - iter->fs;
                dp[0][i] = min(dp[0][i], lmn + rc);
                dp[1][i] = min(dp[1][i], lmn + rc*2);
                ++iter;
            }
        }

        dp[0][n-1] += segs[n].empty() ? 0 : (ll)(segs[n].rbegin()->fs - arr[n-1])*2;
        dp[1][n-1] += segs[n].empty() ? 0 : (ll)(segs[n].rbegin()->fs - arr[n-1]);

        cout << min(dp[0][n-1], dp[1][n-1]) << '\n';
    }
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
// const int MAXN = 1e3;;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dp[260][260][260];
ll pref[260][260];

void u(ll &a, ll b) {
    a = min(a, b);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    
    
    ll n, m;
    cin >> n >> m;

    vector <ll> a(n + 1);
    vector <ll> b(m + 1);
    ll l = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++) {
            b[l++] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + abs(b[i] - j);
        }
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int i1 = 0; i1 <= m; i1++) {
                dp[i][j][i1] = 1e18;
            }
    dp[0][m][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--)
            for (int s = 0; s <= m; s++) {
                if (j > 0) {
                    u(dp[i - 1][j - 1][s], dp[i - 1][j][s]);                    
                }
                if (s + j <= m) {
                    u(dp[i][j][s + j], dp[i - 1][j][s] + pref[j + s][i] - pref[s][i]);
                }
            }
    }

    ll ans = 1e18;

    for (int i = 0; i <= m; i++) u(ans, dp[n][i][m]);
    cout << ans << "\n";

    return 0;
}
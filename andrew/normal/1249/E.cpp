#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 222;
const ll M = 200;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[MAXN], dp1[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    ll n, c;
    cin >> n >> c;

    vector <ll> a(n + 1), b(n + 1);
    for(int i = 1; i < n; i++)cin >> a[i];
    for(int i = 1; i < n; i++)cin >> b[i];

    ll dpa = 0, dpb = c;

    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        dpa += a[i - 1];
        dpb += b[i - 1];
        dp[i] = min(dpa, dpb);
        dpa = min(dpa, dp[i]);
        dpb = min(dpb, dp[i] + c);
    }

    dpa = dp[n];
    dpb = dp[n] + c;

    dp1[n] = dp[n];

    for(int i = n - 1; i > 0; i--){
        dpa += a[i];
        dpb += b[i];
        dp1[i] = min(dpa, dpb);
        dpa = min(dpa, dp1[i]);
        dpb = min(dpb, dp1[i] + c);
    }

    for(int i = 1; i <= n; i++)cout << min(dp[i], dp1[i]) << " ";
    cout << "\n";

    return 0;
}
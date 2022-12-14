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
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n;
    cin >> n;

    vector <ll> a(n + 1), dp(n + 1), pr(n + 1), ans(n + 1);

    map <ll, vector<ll> > mp;

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)mp[a[i]].p_b(i);

    sort(a.begin() + 1, a.end());

    for(auto &i : dp)i = inf;

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 3; j <= min(5, n - i + 1); j++){
            dp[i + j - 1] = min(dp[i + j - 1], dp[i - 1] + a[j + i - 1] - a[i]);
            if(dp[i + j - 1] == dp[i - 1] + a[j + i - 1] - a[i]){
                pr[i + j - 1] = i - 1;
            }
        }
    }

    ll x = n, id = 0;

    while(x){
        ++id;
        for(int i = x; i > pr[x]; i--){
            ans[mp[a[i]].back()] = id;
            mp[a[i]].pop_back();
        }
        x = pr[x];
    }

    cout << dp[n] << " " << *max_element(ans.begin(), ans.begin() + n) << "\n";
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
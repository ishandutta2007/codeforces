#include <bits/stdc++.h>

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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int r, n;
    cin >> r >> n;

    vector <int> t(n + 1), x(n + 1), y(n + 1), dp(n + 1);

    x[0] = y[0] = 1;

    int cn = 2003;

    for(int i = 1; i <= n; i++)dp[i] = -n - 10;

    for(int i = 1; i <= n; i++)cin >> t[i] >> x[i] >> y[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1, i1 = cn; i1 > 0 && j >= 0; i1--, j--){
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}
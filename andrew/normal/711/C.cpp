#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define pil pair<int, ll>

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll dp[101][101][101];
ll val[101][101];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> a(n + 1);

    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
        for(int i1 = 0; i1 < 101; i1++)dp[i][j][i1] = 1e18;

    for(int i = 1; i <= n; i++)cin >> a[i];

    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++)cin >> val[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k + 1; j++){
            multiset <ll> s;
            for(int i1 = 0; i1 <= m; i1++)s.insert(dp[i - 1][j - 1][i1]);
            if(a[i]){
                ll col = a[i];
                dp[i][j][col] = min(dp[i][j][col], dp[i - 1][j][col]);
                s.erase(s.find(dp[i - 1][j - 1][col]));
                if(!s.empty())dp[i][j][col] = min(dp[i][j][col], *s.begin());
                continue;
            }
            for(int i1 = 1; i1 <= m; i1++){
                ll val1 = dp[i - 1][j - 1][i1];
                s.erase(s.find(val1));
                dp[i][j][i1] = min(dp[i][j][i1], dp[i - 1][j][i1] + val[i][i1]);
                dp[i][j][i1] = min(dp[i][j][i1], *(s.begin()) + val[i][i1]);
                s.insert(val1);
            }
        }

    }
    ll ans = 1e18;
    for(int i = 0; i <= m; i++)ans = min(ans, dp[n][k][i]);
    if(ans == 1e18)vout(-1);
    cout << ans << "\n";
    return 0;
}
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
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN], pos[MAXN];

ll dp[5001][5001], r[5001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n + 1), b(n + 1), c(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i] >> b[i] >> c[i];

    while(m--){
        ll u, vt;
        cin >> u >> vt;
        v[vt].p_b(u);
    }

    for(int i = 1; i <= n; i++){
        v[i].p_b(i);
        sort(all(v[i]));
        pos[v[i].back()].p_b(c[i]);
        sort(all(pos[i]));
        reverse(all(pos[i]));
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 5000; j++)dp[i][j] = -inf;

    dp[0][k] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 5000; j++)if(j + b[i] <= 5000 && j >= a[i]){
            dp[i][j + b[i]] = dp[i - 1][j];
        }
        for(auto i1 : pos[i]){
            for(int j = 1; j <= 5000; j++){
                dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + i1);
            }
        }
    }

    cout << max(-1ll, *max_element(dp[n], dp[n] + 5001)) << "\n";
    return 0;
}
#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll W = 9000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll dp[2201][2201];
vector <ll> v[2201];


ll dp1[2201];

inline void u(ll &a, ll b){
    a = max(a, b);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;
    vector <ll> l(n + 1), s(n + 1), c(n + m + 5);

    for(int i = 1; i <= n; i++)cin >> l[i];
    for(int i = 1; i <= n; i++)cin >> s[i];
    for(int i = 1; i <= n + m; i++)cin >> c[i];

    reverse(l.begin() + 1, l.end());
    reverse(s.begin() + 1, s.end());

    for(int i = n; i > 0; i--){
        v[l[i]].p_b(i);
    }

    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= n; j++)dp[i][j] = -inf;
    }

    fill(dp1, dp1 + 2101, -inf);

    ll step, cost, cnt, ans = 0;

    for(int i = 1; i <= n; i++){
        v[l[i]].pop_back();
        for(int j = 1; j <= l[i]; j++)u(dp[i][0], dp1[j]);
        for(int j = n - 1; j >= 0; j--)if(dp[i][j] != -inf)u(dp[i][j + 1], dp[i][j] - s[i] + c[l[i]]);
        if(sz(v[l[i]])){
            for(int j = 0; j <= m; j++)if(dp[i][j] != -inf)
                u(dp[v[l[i]].back()][j], dp[i][j]);
        }
        for(int j = 0; j <= n; j++)if(dp[i][j] != -inf){
            step = l[i];
            cost = dp[i][j];
            cnt = j;
            for(int i1 = l[i]; i1 <= m; i1++){
                if(!cnt){
                    u(dp1[i1], cost);
                    break;
                }
                while(cnt && step < i1){
                    cost += cnt / 2 * c[step + 1];
                    step++;
                    cnt >>= 1;
                }
                if(!v[i1].empty())u(dp[v[i1].back()][cnt], cost);
            }
        }


        for(int j = 0; j <= n; j++)if(dp[i][j] != inf){
            step = l[i];
            cost = dp[i][j];
            cnt = j;
            while(cnt > 1){
                cost += cnt / 2 * c[step + 1];
                step++;
                cnt >>= 1;
            }
            u(ans, cost);
        }
    }

    cout << ans << "\n";

    return 0;
}
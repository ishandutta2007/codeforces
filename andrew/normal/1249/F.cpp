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

vector <ll> v[N];

ll n, k;
ll dp[222][222];
ll ans = 0;
ll a[N], pref[N][N];

void dfs(ll x, ll pr){

    for(auto to : v[x])if(to != pr)dfs(to, x);

    for(auto to : v[x])if(to != pr){
        for(ll level = 0; level <= M; level++){
            ll res = pref[to][level];
            for(auto to1 : v[x])if(to1 != pr && to1 != to)res += pref[to1][max(level, k - level - 2)];
            dp[x][level + 1] = max(dp[x][level + 1], res);
        }
    }

    dp[x][0] = a[x];

    for(auto to : v[x])if(to != pr)dp[x][0] += pref[to][k - 1];

    for(int i = M; i >= 0; i--){
        pref[x][i] = max(pref[x][i + 1], dp[x][i]);
    }

    ans = max(ans, pref[x][0]);

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    cin >> n >> k;
    k++;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll);

    cout << ans << "\n";

    return 0;
}
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
const ll N = 1e3;
const ll inf = 2e9;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll dp[1001][1001];

ll pref[1001][1001];

ll get(ll l, ll r, ll l1, ll r1){
    return pref[r][r1] - pref[r][l1 - 1] - pref[l - 1][r1] + pref[l - 1][l1 - 1];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)dp[i][j] = 1;

    for(int i = 2; i <= m + 1; i++){
        for(int y = 1; y <= n; y++)
            for(int x = 1; x <= n; x++)pref[y][x] = (pref[y - 1][x] + pref[y][x - 1] - pref[y - 1][x - 1] + dp[y][x] + mod) % mod;
        if(i == m + 1)vout(pref[n][n]);
        for(int y = 1; y <= n; y++)
            for(int x = y; x <= n; x++)dp[y][x] = get(1, y, x, n);
    }


    return 0;
}
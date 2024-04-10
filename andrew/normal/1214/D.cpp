#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <bool> a[MAXN], f[MAXN], f1[MAXN];

ll kol[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;

    cin >> n >> m;

    ll ans = 0;

    char kek;
    f[0].resize(m + 2);
    f1[0].resize(m + 2);
    f1[n + 1].resize(m + 2);
    for(int i = 1; i <= n; i++){
        a[i].resize(m + 2);
        f[i].resize(m + 2);
        f1[i].resize(m + 2);
        for(int j = 1; j <= m; j++){
            cin >> kek;
            if(kek == '#')a[i][j] = 1;
        }
    }

    f[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)if(!a[i][j]){
            if(i != 1 || j != 1)f[i][j] = f[i - 1][j] | f[i][j - 1];
        }
    }

    f1[n][m] = 1;

    for(int i = n; i > 0; i--)
    for(int j = m; j > 0; j--)if(!a[i][j]){
        if(i != n || j != m){
            f1[i][j] = f1[i + 1][j] | f1[i][j + 1];
        }
    }

    if(!f[n][m])vout(0);

    if(m > 1 && f[n][m - 1])ans++;
    if(n > 1 && f[n - 1][m])ans++;

    if(ans < 2)vout(ans);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)if(f[i][j] && f1[i][j])kol[i + j - 2]++;

    for(int i = 1; i < n + m - 2; i++){
        if(kol[i] == 1)ans = min(ans, 1ll);
    }

    vout(ans);

    return 0;
}
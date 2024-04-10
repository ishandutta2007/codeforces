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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll h, w;

ll f[2001][2001];

bool f1[2001][2001];
bool f2[2001][2001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll kol = 0;

    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 1; j <= x; j++)f[i][j]++;
        f1[i][x + 1] = 1;
    }

    for(int j = 1; j <= m; j++){
        ll x;
        cin >> x;
        for(int i = 1; i <= x; i++)f[i][j]++;
        f2[x + 1][j] = 1;
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(f[i][j] == 1 && (f1[i][j] || f2[i][j]))vout(0);
        if(!f1[i][j] && !f2[i][j] && f[i][j] == 0)kol++;
    }

    ll ans = 1;

    ll mod = 1e9 + 7;

    while(kol--){
        ans *= 2;
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}
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

ll ans = 0, n, m;

vector <ll> c;

vector <pll> a;

bool f[8][8];

void dfs(ll x){
    c.p_b(x);
    if(c.size() == n){
        ll sc = 0;
        for(int i = 1; i <= 6; i++)
        for(int j = i; j <= 6; j++)f[i][j] = 0;

        for(auto i : a){
            ll x, y;
            x = c[i.fi - 1], y = c[i.se - 1];
            if(x > y)swap(x, y);
            if(!f[x][y]){
                f[x][y] = 1;
                sc++;
            }
        }
        ans = max(ans, sc);

    }
    if(c.size() < n)for(int i = 1; i <= 6; i++)dfs(i);
    c.pop_back();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    a.resize(m);

    for(int i = 0; i < m; i++)cin >> a[i].fi >> a[i].se;

    for(int i = 1; i <= 6; i++)dfs(i);

    cout << ans << "\n";

    return 0;
}
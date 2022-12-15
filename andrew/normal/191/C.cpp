#include <bits/stdc++.h>
#define p_b push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
const ll MAXN = 1123456;
const ll N = 1e5;

vector <pll> v[MAXN];

ll del[MAXN], sum[MAXN];

ll p[N + 5][18], stn, tin[N + 5], tout[N + 5];

void dfs(ll x, ll pr){
    tin[x] = ++stn;

    p[x][0] = pr;

    for(auto to : v[x])if(to.fi != pr)dfs(to.fi, x);

    tout[x] = stn;

}

bool is_less(ll a, ll b){
    if(tin[b] <= tin[a] && tout[a] <= tout[b])return 1;
    return 0;
}

ll lca(ll a, ll b){
    if(is_less(a, b))return b;
    if(is_less(b, a))return a;
    for(int i = 17; i >= 0; i--)if(!is_less(b, p[a][i]))a = p[a][i];
    return p[a][0];
}

ll ans = 0;

ll res[MAXN];

void go(ll x, ll pr){

    for(auto to : v[x])if(to.fi != pr){
        go(to.fi, x);
        res[to.se] += sum[to.fi];
        sum[x] += sum[to.fi];
    }
    sum[x] -= 2 * del[x];

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    tout[0] = 1e18;
    ll n, q;
    cin >> n;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b({b, i});
        v[b].p_b({a, i});
    }

    dfs(1ll, 0ll);

    for(int j = 1; j < 18; j++){
        for(int i = 1; i <= n; i++)p[i][j] = p[p[i][j - 1]][j - 1];
    }

    cin >> q;

    while(q--){
        ll a, b;
        cin >> a >> b;
        sum[a]++;
        sum[b]++;
        del[lca(a, b)]++;
    }

    go(1ll, 0ll);

    for(int i = 1; i < n; i++)cout << res[i] << " ";cout << "\n";

    return 0;
}
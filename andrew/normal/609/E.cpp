#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector <pll> v[MAXN];

vector <ll> pred, tin, tout;

ll get(ll x){
    if(pred[x] != x)pred[x] = get(pred[x]);
    return pred[x];
}

ll p[200011][19], cost[201111][19], stn;

void dfs(ll x, ll pr, ll val = 0){
    tin[x] = ++stn;
    p[x][0] = pr;
    cost[x][0] = val;
    for(auto to : v[x])if(to.fi != pr)dfs(to.fi, x, to.se);
    tout[x] = stn;
}

bool is_lower(ll a, ll b){
    if(tin[b] <= tin[a] && tout[a] <= tout[b])return 1;
    return 0;
}

ll f(ll a, ll b){
    ll c = a, ans = 0;
    for(int i = 18; i >= 0; i--)if(!is_lower(b, p[c][i])){
        ans = max(ans, cost[c][i]);
        c = p[c][i];
    }

    if(!is_lower(b, c)){
        ans = max(ans, cost[c][0]);
    }

    c = b;

    for(int i = 18; i >= 0; i--)if(!is_lower(a, p[c][i])){
        ans = max(ans, cost[c][i]);
        c = p[c][i];
    }

    if(!is_lower(a, c)){
        ans = max(ans, cost[c][0]);
    }

    return ans;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;

    cin >> n >> m;

    vector <ll> a(m), b(m), c(m);
    vector < pair <ll, pll> > d(m);

    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i];
        d[i] = {c[i], {a[i], b[i]}};
    }

    pred.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);

    for(int i = 1; i <= n; i++)pred[i] = i;

    sort(all(d));

    ll ans = 0;

    map <pll, ll> mp;

    for(int i = 0; i < m; i++){
        if(get(d[i].se.fi) != get(d[i].se.se)){
            ans += d[i].fi;
            mp[d[i].se] = 1;
            pred[get(d[i].se.fi)] = get(d[i].se.se);
            v[d[i].se.fi].p_b({d[i].se.se, d[i].fi});
            v[d[i].se.se].p_b({d[i].se.fi, d[i].fi});
        }
    }

    tout[0] = 1e18;
    dfs(1ll, 0ll);

    for(int j = 1; j < 19; j++)
    for(int i = 1; i <= n; i++){
        p[i][j] = p[p[i][j - 1]][j - 1];
        cost[i][j] = max(cost[i][j - 1], cost[p[i][j - 1]][j - 1]);
    }

    for(int i = 0; i < m; i++){
        if(mp[{a[i], b[i]}]){
            cout << ans << "\n";
            continue;
        }
        ll sc = ans + c[i];
        sc -= f(a[i], b[i]);
        cout << sc << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
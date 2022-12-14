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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1e6 + 123456;
const ll N = 1e5 + 10;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector <ll> v[N], d[N];

ll deep[N], stn, tin[N], tout[N], pr[N][18];

ll upper(ll x, ll k){
    for(int i = 17; i >= 0; i--)if((1ll << i) <= k)x = pr[x][i], k -= 1ll << i;
    return x;
}

void dfs(ll x, ll p = 0){
    pr[x][0] = p;
    deep[x] = deep[p] + 1;
    tin[x] = ++stn;
    d[deep[x]].p_b(tin[x]);
    for(auto to : v[x])dfs(to, x);
    tout[x] = stn;
}

ll kol(ll dp, ll l, ll r){
    return upper_bound(all(d[dp]), r) - lower_bound(all(d[dp]), l);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        v[x].p_b(i);
    }
    dfs(0ll);

    for(int j = 1; j < 18; j++)
        for(int i = 1; i <= n; i++)pr[i][j] = pr[pr[i][j - 1]][j - 1];

    ll q;
    cin >> q;
    while(q--){
        ll x, p;
        cin >> x >> p;
        ll D = upper(x, p), res = 0;

        if(D){
            res = kol(deep[x], tin[D], tout[D]) - 1;
        }

        cout << res << " ";

    }
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
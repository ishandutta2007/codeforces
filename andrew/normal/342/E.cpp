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
typedef int ll;
const ll MAXN = 1123456;

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

const ll N = 1e5 + 10;

ll root[5 * MAXN], r;

multiset <ll> s[5 * MAXN];

bool f[N];

vector <ll> v[N];
vector <ll> c[N];
vector <ll> d[N];

ll dfs1(ll x, ll p){
    c[x].p_b(r);
    ll sc = 1;

    for(auto i : v[x])if(i != p && !f[i])sc += dfs1(i, x);

    return sc;

}

ll dfs(ll x, ll &centroid, ll p, ll size){
    ll su = 1;

    for(auto to : v[x])if(to != p && !f[to]){
        su += dfs(to, centroid, x, size);
    }

    if(!centroid && (p == 0 || 2 * su >= size))centroid = x;

    return su;


}

void build(ll x){
    r++;

    ll _size = dfs1(x, 0ll), centroid = 0;

    dfs(x, centroid, 0ll, _size);

    root[r] = centroid;

    f[root[r]] = 1;

    for(auto to : v[root[r]])if(!f[to])build(to);

}

ll tin[N], tout[N], pr[111111][18], deep[N], stn;

void go(ll x, ll p, ll gl){
    pr[x][0] = p;
    tin[x] = ++stn;
    deep[x] = gl;

    for(auto to : v[x])if(to != p)go(to, x, gl + 1);

    tout[x] = stn;

}

bool is_less(ll a, ll b){
    if(tin[a] <= tin[b] && tout[b] <= tout[a])return 1;
    return 0;
}

ll lca(ll a, ll b){
    if(is_less(a, b))return a;
    if(is_less(b, a))return b;

    for(int i = 17; i >= 0; i--)if(!is_less(pr[a][i], b))a = pr[a][i];

    return pr[a][0];;
}

ll dist(ll a, ll b){
    ll k = lca(a, b);
    return deep[a] + deep[b] - 2 * deep[k];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    tout[0] = 1e9;

    ll n, q;

    cin >> n;
    cin >> q;

    ll m = n - 1;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    go(1ll, 0ll, 0ll);

    for(int i = 1; i < 18; i++)
        for(int j = 1; j <= n; j++)pr[j][i] = pr[pr[j][i - 1]][i - 1];

    build(1ll);

    for(int i = 1; i <= n; i++){
        for(auto j : c[i]){
            d[i].p_b(dist(i, root[j]));
        }
    }

    ll x = 1;

    for(int j = 0; j < c[x].size(); j++){
            s[c[x][j]].insert(d[x][j]);
        }

    while(q--){
        ll t;
        cin >> t;

        if(t == 1){
            ll x;
            cin >> x;

            for(int j = 0; j < c[x].size(); j++){
                s[c[x][j]].insert(d[x][j]);
            }



        }else{

            ll x;
            cin >> x;

            ll ans = 1e9;

            for(int i = 0; i < c[x].size(); i++){
                if(!s[c[x][i]].empty()){
                    ans = min(ans, d[x][i] + *s[c[x][i]].begin());
                }
            }

            cout << ans << "\n";

        }

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
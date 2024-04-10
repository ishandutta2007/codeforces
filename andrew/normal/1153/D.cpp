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

vector <ll> v[MAXN];

ll ans = 1e18;

ll f[MAXN], pr[MAXN], a[MAXN], n, k, kol1[MAXN], kol2[MAXN];

void go(ll x){
    if(v[x].empty()){
        kol1[x] = 1;
        kol2[x] = 1;
        return;
    }

    if(f[x])kol2[x] = 1e18;

    for(auto to : v[x]){
        go(to);
        kol1[x] += kol1[to];
        if(!f[x])kol2[x] += kol2[to]; else kol2[x] = min(kol2[x], kol2[to]);
    }

}

void dfs(ll x, ll kol){
    if(v[x].empty()){
        ans = min(ans, kol);
        return;
    }
    ll sc = 0;
    if(!f[x]){
        sc = kol2[x];
    }
    for(auto to : v[x]){
        if(!f[x])sc -= kol2[to];
        dfs(to, kol + sc);
        if(!f[x])sc += kol2[to];
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;

    for(int i = 1; i <= n; i++)cin >> f[i];

    for(int i = 2; i <= n; i++){
        ll x;
        cin >> x;
        v[x].p_b(i);
        pr[i] = x;
    }

    for(int i = 1; i <= n; i++)if(v[i].empty())k++;
    go(1ll);
    dfs(1ll, 0ll);

    cout << k - ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
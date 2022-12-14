#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
mt19937_64 gen;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll le[MAXN], ri[MAXN];

bool f[MAXN];

ll cv[MAXN];

ll stn = 1e5;

void dfs(ll x){
    if(f[x])return;
    f[x] = 1;
    cv[x] = stn;
    for(int i = le[x]; i <= ri[x]; i++)dfs(i);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector <pll> t;

    for(int i = 1; i <= n; i++)le[i] = ri[i] = i;

    while(m--){
        ll x, l, r;
        cin >> x >> l >> r;
        if(x == 1){
            for(int i = l; i <= r; i++)le[i] = min(le[i], l), ri[i] = max(ri[i], r);
        }else{
            t.p_b({l, r});
        }
    }

    for(int i = 1; i <= n; i++)if(!f[i]){
        stn--;
        dfs(i);
    }
    //for(int i = 1; i <= n; i++)cout << cv[i] << " ";

    for(auto i : t){
        ll mx = -1e18;
        bool fl = 0;
        for(int j = i.fi; j <= i.se; j++){
            mx = max(mx, cv[j]);
            if(mx > cv[j])fl = 1;
        }
        if(!fl)vout("NO");
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++)cout << cv[i] << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
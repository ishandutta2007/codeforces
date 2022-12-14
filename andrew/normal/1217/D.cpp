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

bool good = 1;

vector <ll> v[MAXN];

ll f[MAXN];

void dfs(ll x){
    if(f[x] == 1){
        good = 0;
        return;
    }
    if(f[x] == 2)return;
    f[x] = 1;
    for(auto to : v[x])dfs(to);
    f[x] = 2;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector <pll> a(m);

    for(int i = 0; i < m; i++){
        cin >> a[i].fi >> a[i].se;
        v[a[i].fi].p_b(a[i].se);
    }

    for(int i = 1; i <= n; i++)dfs(i);

    if(good){
        cout << "1\n";
        for(int i = 1; i <= m; i++)cout << "1 ";
        cout << "\n";
        return 0;
    }

    cout << "2\n";

    for(int i = 0; i < m; i++){
        if(a[i].fi < a[i].se)cout << "1 ";
        else cout << "2 ";
    }
    cout << "\n";

    return 0;
}
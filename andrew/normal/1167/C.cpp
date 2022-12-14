#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
const ll N = 1e6 + 5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

ll ans[MAXN];
bool f[MAXN];

ll res;

set <ll> s;

void dfs(ll x){
    if(f[x])return;
    f[x] = 1;
    res++;
    s.insert(x);
    for(auto to : v[x])dfs(to);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll k;
        cin >> k;
        if(k){
            vector <ll> a(k);
            for(int i = 0; i < k; i++)cin >> a[i];
            for(int i = 1; i < k; i++){
                v[a[0]].p_b(a[i]);
                v[a[i]].p_b(a[0]);
            }
        }
    }

    for(int i = 1; i <= n; i++)if(!f[i]){
        s.clear();
        res = 0;
        dfs(i);
        for(auto i : s)ans[i] = res;
    }

    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
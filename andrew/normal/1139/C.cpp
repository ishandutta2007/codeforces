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

const ll mod = 1e9 + 7;

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

vector <pll> v[MAXN];

ll val[MAXN], val1[MAXN], n, k, ans = 0;

ll r;
bool f[MAXN];

void dfs(ll x){
    if(f[x])return;
    r++;
    f[x] = 1;
    for(auto to : v[x])if(to.se == 0)dfs(to.fi);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> k;
    //ll ans = 0;
    for(int i = 1; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].p_b({b, c});
        v[b].p_b({a, c});
    }

    ll ans = bp(n, k);

    for(int i = 1; i <= n; i++)if(!f[i]){
        r = 0;
        dfs(i);
        ans -= bp(r, k);
        ans += mod;
        ans %= mod;
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
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

const ll N = 2e5 + 10;


vector <ll> a;

vector <ll> v[MAXN];

set <pll> s[MAXN];

ll last[MAXN];

ll deep[MAXN];

ll ans = 0;


struct SET{
    int x = -1e9, y = -1e9;

    void insert(int val){
        if(y < val)y = val;
        if(x < y)swap(x, y);
    }

};

map <pll, ll> mp;

void dfs(ll x, ll pr){

    deep[x] = deep[pr] + 1;

    for(auto to : v[x])if(to != pr){
        dfs(to, x);
    }

    while(a[x] != 1){
        ll val = last[a[x]];
        SET T;
        for(auto to : v[x])if(to != pr)T.insert(mp[{to, val}]);
        ans = max(ans, T.x + T.y - 2 * deep[x] + 1);
        mp[{x, val}] = max(deep[x], ll(T.x));
        ans = max(ans, max(deep[x], ll(T.x)) - deep[x] + 1);
        while(a[x] % val == 0)a[x] /= val;
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    a.resize(n + 1);

    for(int i = 2; i <= N; i++)if(!last[i]){
        for(int j = i; j <= N; j += i)last[j] = i;
    }

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
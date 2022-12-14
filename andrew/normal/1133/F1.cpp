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
#define hash sosat

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll mod = 42;
const ll mod1 = 998244353;

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
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

ll bp1(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod1;
        (a *= a) %= mod1;
        n >>= 1;
    }
    return res;
}

vector <ll> v[MAXN];

vector <ll> us;
ll d;
bool f[MAXN], ok[MAXN];

vector <pll> ans;

void dfs(ll x){
    f[x] = 1;
    for(auto to : v[x])if(!f[to]){
        ans.p_b({x, to});
        dfs(to);
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    ll wh = 1;


    for(int i = 2; i <= n; i++)if(v[i].size() > v[wh].size())wh = i;

    f[wh] = 1;

    for(auto i : v[wh])f[i] = 1;

    for(auto i : v[wh]){
        ans.p_b({wh, i});
        dfs(i);
    }

    dfs(wh);

    for(auto i : ans)cout << i.fi << " " << i.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
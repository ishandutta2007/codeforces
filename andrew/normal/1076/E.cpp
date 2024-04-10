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


ll p[MAXN], n, ans[MAXN];

vector <ll> v[MAXN];
vector <pll> d[MAXN];

void dfs(ll x, ll pr, ll deep, ll res){
    for(auto i : d[x]){
            if(deep + i.fi < MAXN)p[deep + i.fi] += i.se;
            res += i.se;
    }
    ans[x] = res;
    res -= p[deep];
    for(auto to : v[x])if(to != pr)dfs(to, x, deep + 1, res);
    for(auto i : d[x])if(deep + i.fi < MAXN)p[deep + i.fi] -= i.se;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("numbers.in","r",stdin);
    //freopen("numbers.out","w",stdout);


    ll n;
    cin >> n;
    ll m = n - 1;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    ll q;
    cin >> q;
    while(q--){
        ll x, y, val;
        cin >> x >> y >> val;
        d[x].p_b({y, val});
    }

    dfs(1ll, 0ll, 0ll, 0ll);
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
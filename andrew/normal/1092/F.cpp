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

vector <ll> v[MAXN];

vector <ll> a;

ll kol[MAXN], ans = 0, dist;

void dfs(ll x, ll pr, ll deep){
    dist += deep * a[x];

    kol[x] = a[x];

    for(auto to : v[x])if(to != pr){
        dfs(to, x, deep + 1);
        kol[x] += kol[to];
    }

}

ll n, sc;

void f(ll x, ll pr, ll res){
    ans = max(ans, res);

    for(auto to : v[x])if(to != pr)f(to, x, res - kol[to] + sc - kol[to]);

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("teamwork.in","r",stdin);
    //freopen("balance.in","w",stdout);

    cin >> n;

    ll q = n - 1;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)sc += a[i];

    while(q--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll, 0ll);
    f(1ll, 0ll, dist);

    cout << ans << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
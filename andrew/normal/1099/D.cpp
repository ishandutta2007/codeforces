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

ll ans;

ll p[MAXN], s[MAXN];

void dfs(ll x, ll deep){

    for(auto to : v[x])dfs(to, 1 - deep);

    if(deep == 0){
        ll res = 1e18;
        if(v[x].empty())return;

        for(auto to : v[x]){
            if(s[to] < s[p[x]])vout(-1);
            res = min(res, s[to] - s[p[x]]);
        }

        ans += res;
        for(auto to : v[x])ans += s[to] - s[p[x]] - res;

    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;

    cin >> n;

    for(int i = 2; i <= n; i++){
        ll x;
        cin >> x;
        p[i] = x;
        v[x].p_b(i);
    }

    for(int i = 1; i <= n; i++)cin >> s[i];

    ans = s[1];

    dfs(1ll, 1ll);


    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
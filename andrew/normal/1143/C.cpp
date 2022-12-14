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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
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

ll f(ll x){
    ll pr = 1;

    while(x){
        pr *= x % 10;
        x /= 10;
    }
    return pr;

}

ll kol[MAXN], p[MAXN], c[MAXN];

vector <ll> v[MAXN];

set <ll> s;

ll pr[MAXN];

void dfs(ll x){
    for(auto to : v[x]){
        dfs(to);
        if(!c[to])kol[x]++;
    }
    if(c[x] && !kol[x])s.insert(x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> p[i] >> c[i];
        if(p[i] == -1)p[i] = 0;
        v[p[i]].p_b(i);
    }

    vector <ll> ans;

    dfs(0);

    while(!s.empty()){
        ll x = *s.begin();
        s.erase(s.begin());
        ans.p_b(x);
    }
    if(ans.empty())vout(-1);

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    cerr << "time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
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
typedef int ll;
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

vector <pll> a, b;
ll n, m;

bool check(ll x){
    for(int i = 0; i < m; i++){
        b[i] = a[i];
        b[i].fi += x;
        b[i].se += x;
        if(b[i].fi > n)b[i].fi -= n;
        if(b[i].se > n)b[i].se -= n;
        if(!b[i].fi)b[i].fi = n;
        if(!b[i].se)b[i].se = n;
        if(b[i].fi > b[i].se)swap(b[i].se, b[i].fi);
    }
    sort(all(b));
    if(a == b)return 1;
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;
    a.resize(m);
    b.resize(m);


    for(int i = 0; i < m; i++){
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi > a[i].se)swap(a[i].se, a[i].fi);
    }
    sort(all(a));
    ll ans = 1e18;

    for(int i = 1; i < n; i++)if(n % i == 0 && check(i))vout("Yes");
    cout << "No\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
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

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    set <ll> s;

    for(int i = 1; i <= m; i++){
        ll x;
        cin >> x;
        s.insert(x);
    }

    ll l = 0, r = 3e9;

    while(l < r){
        ll c = (l + r) >> 1;
        bool f = 1;
        for(int i = 1; i <= n; i++){
            ll le = a[i] - c, ri = a[i] + c;
            if(s.lower_bound(le) != s.end()){
                ll x = *s.lower_bound(le);
                if(!(x <= ri))f = 0;
            }else f = 0;
        }
        if(f)r = c; else l = c + 1;
    }

    cout << l << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
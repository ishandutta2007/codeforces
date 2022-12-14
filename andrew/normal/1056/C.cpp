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

set <pll> s;

ll kek(ll x){
    ll ans = 0;
    cout << x << endl;
    if(s.empty())exit(0);
    cin >> ans;
    return ans;
}
vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n * 2 + 2);

    for(int i = 1; i <= n * 2; i++){
        cin >> a[i];
        s.insert({a[i], i});
    }

    vector <pll> b(m);

    for(int i = 0; i < m; i++)cin >> b[i].fi >> b[i].se;
    for(int i = 0; i < m; i++){
        v[b[i].fi].p_b(b[i].se);
        v[b[i].se].p_b(b[i].fi);
    }



    ll t;
    cin >> t;
    if(t == 1){

        while(m--){
            ll l = b[m].fi, r = b[m].se;
            if(a[l] > a[r]){
                kek(l);
            }else kek(r);
            s.erase({a[l], l});
            s.erase({a[r], r});
        }



        while(!s.empty()){
            pll xe = *(--s.end());
            ll x = kek(xe.se);
            s.erase(--s.end());
            s.erase({a[x], x});
        }

    }else{
        ll x;
        cin >> x;
        while(v[x].size()){
            s.erase({a[x], x});
            x = v[x][0];
            s.erase({a[x], x});
            x = kek(x);
            if(s.empty())return 0;
            
        }

        s.erase({a[x], x});

        for(int i = 0; i < m; i++){
            ll l, r;
            l = b[i].fi, r = b[i].se;
            if(s.find({a[l], l}) != s.end()){
                if(a[l] > a[r]){
                kek(l);
                }else kek(r);
                s.erase({a[l], l});
                s.erase({a[r], r});
            }
        }
        while(!s.empty()){
            pll xe = *(--s.end());
            s.erase(--s.end());
            ll x = kek(xe.se);
            
            s.erase({a[x], x});
        }

    }



    return 0;
}
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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    vector <ll> x(n), y(n);

    vector <ll> a(n), b(n);

    for(int i = 0; i < n; i++)cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)cin >> a[i] >> b[i];

    map <pll, ll> mp;

    for(int i = 1; i < n; i++){
        mp[{x[i], y[i]}]++;
    }

    for(int i = 0; i < n; i++){
        ll tx = x[0] + a[i],  ty = y[0] + b[i];

        vector <pll> c;

        bool fl = 0;

        for(int j = 0; j < n; j++)if(i != j){
            ll x = tx - a[j], y = ty - b[j];
            if(mp[{x, y}]){
                c.p_b({x, y});
                mp[{x, y}]--;
            }else fl = 1;
        }

        if(!fl){
            cout << tx << " " << ty << "\n";
            return 0;
        }

       for(auto j : c)mp[j]++;


    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
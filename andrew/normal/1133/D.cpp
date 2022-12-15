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
#define pw(x) (1ll << x)

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

    ll n;
    cin >> n;
    vector <ll> a(n), b(n);

    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];

    map <pll, ll> mp;
    ll ans = 0, sc = 0, val = 0;
    for(int i = 0; i < n; i++){

        if(!a[i]){
            if(!b[i])sc++;
            continue;
        }

        if(!b[i]){
            if(!a[i])sc++;
            else val++;
            continue;
        }

        ll val = -b[i];
        bool fk = 0;
        if(a[i] < 0)fk ^= 1;
        if(b[i] < 0)fk ^= 1;

        ll x = abs(a[i]), y = abs(b[i]), k = __gcd(x, y);
        x /= k;
        y /= k;
        if(fk)x *= -1;
        mp[{x, y}]++;
        ans = max(ans, mp[{x, y}]);

    }
    ans = max(ans, val);
    cout << ans + sc << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
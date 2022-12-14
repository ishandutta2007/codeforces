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

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll xx, yy;
    xx = 0, yy = 0;
    s = "+" + s;

    vector <pll> b(n + 1);

    for(int i = 1; i <= n; i++){
        if(s[i] == 'U')yy++;
        if(s[i] == 'D')yy--;
        if(s[i] == 'L')xx--;
        if(s[i] == 'R')xx++;
        b[i] = {xx, yy};
    }

   ll l = 1, r = 1e15;

   b[0] = {0ll, 0ll};

   while((r - l > 30)){
        ll c1 = l + (r - l + 1) / 3, c2 = r - (r - l + 1) / 3;

        ll xm = x1 + xx * (c1 / n) + b[c1 % n].fi;
        ll ym = y1 + yy * (c1 / n) + b[c1 % n].se;

        ll xm1 = x1 + xx * (c2 / n) + b[c2 % n].fi;
        ll ym1 = y1 + yy * (c2 / n) + b[c2 % n].se;

        ll rr = abs(xm - x2) + abs(ym - y2) - c1;
        ll r1 = abs(xm1 - x2) + abs(ym1 - y2) - c2;

        if(rr <= 0)r = c2; else
        if(rr < r1)r = c2; else l = c1;

   }
    ll ans = 5e18;

    for(ll i = l; i <= r; i++){
         ll xm = x1 + xx * (i / n) + b[i % n].fi;
         ll ym = y1 + yy * (i / n) + b[i % n].se;

         ll rr = abs(xm - x2) + abs(ym - y2) - i;
         if(rr <= 0)ans = min(ans, i);
    }

    if(ans == 5e18)vout(-1);
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
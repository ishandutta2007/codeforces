#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

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

pll per(ll x, ll y, ll x1, ll y1, ll xx, ll yy, ll xx1, ll yy1){
    ll A = y1 - y, B = x - x1, C = -A * x - B * y;
    ll A1 = yy1 - yy, B1 = xx - xx1, C1 = -A1 * xx - B1 * yy;
    pll cler = m_p(1e18, 1e18);
    if(A * B1 == B * A1)return cler;
    ll chisl = -B1 * C + B * C1;
    ll znam = -B * A1 + B1 * A;
    if(chisl % znam)return cler;
    ll xans = chisl / znam;
    ll yans;
    if(B){
        chisl = - A * xans - C;
        znam = B;
    }else{
        chisl = -A1 * xans - C1;
        znam = B1;
    }

    if(chisl % znam)return cler;
    yans = chisl / znam;
    if(!(min(x, x1) <= xans && xans <= max(x, x1)))return cler;
    if(!(min(xx, xx1) <= xans && xans <= max(xx, xx1)))return cler;
    if(!(min(y, y1) <= yans && yans <= max(y, y1)))return cler;
    if(!(min(yy, yy1) <= yans && yans <= max(yy, yy1)))return cler;
    return {xans, yans};

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> x(n), y(n), x1(n), y1(n);
    for(int i = 0; i < n; i++)cin >> x[i] >> y[i] >> x1[i] >> y1[i];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += __gcd(abs(y[i] - y1[i]), abs(x[i] - x1[i])) + 1;
        set <pll> coord;
        for(int j = i + 1; j < n; j++)if(per(x[i], y[i], x1[i], y1[i], x[j], y[j], x1[j], y1[j]).fi != 1e18)coord.insert(per(x[i], y[i], x1[i], y1[i], x[j], y[j], x1[j], y1[j]));
        ans -= coord.size();
    }
    cout << ans << "\n";
    return 0;
}
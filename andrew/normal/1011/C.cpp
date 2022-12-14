#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

ll n, m;
pair <double, double> a[MAXN];
bool check(double x){
    for (int i = 0; i < n; ++i){
        x = x - (m + x) / a[i].fi;
        x = x - (m + x) / a[i + 1].se;
    }
    if (x >= 0) return 1;
    return 0;
}
int main() {
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i].fi;
    for (int i = 0; i < n ; i++)cin >> a[i].se;
    a[n].se = a[0].se;
    long double l = 0, r = 1e9 + 1;
    while (r - l > 1e-6){
        double c = (l + r) / 2.0;
        if (check(c))r = c; else l = c;
    }
    if(l > 1e9)vout(-1);
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

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

bool comp(ld &a, ld &b){
    if(a - b <= 1e-9)return 1;
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    vector <pll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    ll ans = 0;
    map <pll, ll> mp;
    map < pll, vector <ld> > f;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll ax = a[i].fi - a[j].fi, ay = a[i].se - a[j].se;
            bool fx, fy;
            fx = fy = 0;
            if(ax < 0)fx = 1, ax *= -1;
            if(ay < 0)fy = 1, ay *= -1;

            if(!ay)ax = 1, fx = fy = 0;
            if(!ax)ay = 1, fy = fx = 0;

            ll k = __gcd(ax, ay);
            ax /= k;
            ay /= k;
            if(fx && fy)fx = 0, fy = 0;
            if(fy)swap(fx, fy);
            if(fx)ax *= -1;
            if(fy)ay *= -1;
            ld A = a[i].se - a[j].se, B = a[j].fi - a[i].fi, C = -A * a[i].fi - B * a[i].se;
            ld x;
            if(a[j].fi - a[i].fi != 0){
                x = -C / B;
            }else{
                x = -C / A;
            }
            f[{ax, ay}].p_b(x);
        }
    }

    ll kol = 0;

    vector <ll> v;

    for(auto i : f){
        vector <ld> kek = i.se;
        ll sc = 0;
        sort(all(kek), comp);
        sc = 1;
        for(int i = 1; i < kek.size(); i++)if(abs(kek[i] - kek[i - 1]) > 1e-9)sc++;
        v.p_b(sc);
        kol += sc;
    }

    for(auto i : v)ans += i * (kol - i);

    cout << ans / 2 << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ld ans = 0;
    ll n, p;
    cin >> n >> p;
    vector <pll> a(n + 2);
    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    a[n] = a[0];

    for(int i = 0; i < n; i++){
        ll l = a[i].fi, r = a[i].se, l1 = a[i + 1].fi, r1 = a[i + 1].se;
        ld znam = (r - l + 1) * (r1 - l1 + 1);
        ll kek = l / p;
        if(l % p)kek ++;
        ll le = kek * p;
        ll kol = 0;
        ll kkk = 0;
        if(le <= r){
            ll kol1 = 0;
            kol1++;
            kol1 += (r - le) / p;
            kkk = kol1;
            kol += kol1 * (r1 - l1 + 1);
        }
        kek = l1 / p;
        if(l1 % p)kek++;
        le = kek * p;
        if(le <= r1){
            ll kol1 = 1;
            kol1 += (r1 - le) / p;
            kol += kol1 * (r - l + 1 - kkk);
        }
        ld chisl = kol * 1000.0;
        ans += (chisl / znam);
    }
    ans *= 2;
    cout << fixed << setprecision(7) << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
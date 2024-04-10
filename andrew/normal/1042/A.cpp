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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("joseph.in", "r", stdin);
    //freopen("joseph.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    ll mx = -1e18;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll sc = 0;
    for(int i = 0; i < n; i++)sc += mx - a[i];
    if(sc >= m){
        cout << mx << " " << mx + m << "\n";
        return 0;
    }
    ll a1 = mx + m;
    m -= sc;
    ll kol = m / n;
    if(m % n)kol++;
    cout << mx + kol << " " << a1 << "\n";
    return 0;
}
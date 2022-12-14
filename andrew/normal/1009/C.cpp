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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    ll s = 0;
    ll mx = -1e18, mn = 1e18;
    for(int i = 1; i < n; i++)s += i;
    for(int i = 1; i <= n; i++){
        mx = max(mx, s);
        mn = min(mn, s);
        s += i;
        s -= n - i;
    }
    ll sc = 0;
    while(m--){
        ll a, b;
        cin >> a >> b;
        sc += n * a;
        sc += max(b * mx, b * mn);
    }
    double su = sc;
    su /= n;
    cout << fixed << setprecision(7) << su << endl;
    return 0;
}
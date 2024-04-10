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
    ll n, m;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    cin >> m;
    vector <ll> b(m);
    for(int i = 0; i < m; i++)cin >> b[i];
    ll sc = 0, sc1 = 0;
    for(int i = 0; i < n; i++)sc += a[i];
    for(int i = 0; i < m; i++)sc1 += b[i];
    if(sc != sc1)vout(-1);
    ll l = 0;
    ll ans = 0;
    for(int i = 0; i < n;){
        sc = a[i];
        sc1 = 0;
        while(sc != sc1){
            while(sc < sc1){
                i++;
                sc += a[i];
            }
            while(sc1 < sc){
                sc1 += b[l];
                l++;
            }
        }
        ans++;
        i++;
    }
    vout(ans);
    return 0;
}
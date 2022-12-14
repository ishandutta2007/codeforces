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

int main() {
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll n, k;
    cin >> n >> k;
    ll g = k;
    while(n--){
        ll x;
        cin >> x;
        x %= k;
        g = __gcd(g, x);
    }
    cout << k / g << endl;
    for(int i = 0; i < k / g; i++)cout << i * g << " ";
    return 0;
}
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

bool f(ll l, ll r){
    cout << l << " " << r << endl;
    string a;
    cin >> a;
    if(a == "Yes")return 1;
    return 0;
}

int main(){
    srand(time(0));
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    while(l < r){
       if(abs(r - l + 1) <= min(n, 50ll)){
            ll x = rand() % (r - l + 1) + l;
            if(f(x, x))return 0;
            l -= k; r += k;
            l = max(1ll, l);
            r = min(r, n);
       }else{
            ll c = (l + r) >> 1;
            if(f(l, c)){
                r = c + k;
                r = min(r, n);
                l -= k;
                l = max(1ll, l);
            }else {
                r += k;
                r = min(r, n);
                l = c - k;
                l = max(1ll, l);
            }
       }
    }
    f(l, r);
    return 0;
}
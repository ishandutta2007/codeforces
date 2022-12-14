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

bool is(char a){
    if('a' <= a && a <= 'z')return 1;
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    while(q--){
        ll y, x;
        cin >> x >> y;
        ll su = (y + x) % 2;
        if(su == 0){
            ll k = x - 1;
            ll a = k / 2, b = k - a;
            ll kol = a * (n / 2) + b * (n - n / 2);
            if(x % 2 == 0)kol += (y - 1) / 2; else kol += y / 2;
            cout << 1 + kol << "\n";
        }else{
            ll k = x - 1;
            ll a = k / 2, b = k - a;
            ll kol = a * (n - n / 2) + b * (n / 2);
            if(x % 2 == 0)kol += y / 2; else kol += (y - 1) / 2;
            //cout << "kek " << kol << endl;
            cout << (n * n + 1) / 2 + kol + 1 << "\n";
        }
    }
    return 0;
}
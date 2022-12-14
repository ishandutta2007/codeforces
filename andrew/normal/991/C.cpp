#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
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
bool check(ll k, ll n){
    ll res = 0;
    ll mb = (n + 1) / 2;
    while(n != 0){
                             res += min(n, k);
                             n -= min(n, k);
                             if(res >= mb)return 1;
                             n -= n / 10;
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   ll n;
   cin >> n;
   ll l = 1, r = n;
   while(l < r){
                            ll c = (l + r) >> 1;
                            if(check(c, n) == 1)r = c; else l = c + 1;
   }
   vout(l);
    return 0;
 }
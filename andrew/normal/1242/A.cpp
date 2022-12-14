#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool is_prime(ll x){
    for(ll i = 2; i * i <= x; i++)if(x % i == 0)return 0;
    return 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    if(is_prime(n))vout(n);

    ll x = sqrt(n);
    while(x * x < n)x++;
    while(x * x > n)x--;
    if(x * x == n && is_prime(x))vout(x);

    ll con = 2e4;

    for(ll i = 2; i <= con; i++)if(is_prime(i) && (n % i == 0)){
        while(n % i == 0)n /= i;
        if(n == 1)vout(i);
        vout(1);
    }

    vout(1);

    return 0;
}
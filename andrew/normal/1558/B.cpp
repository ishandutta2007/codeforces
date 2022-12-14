#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>

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
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long N = 8e6 + 200;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll u[N], n, mod, dp[N];

void up(ll &a, ll b){
    a += b;
    if(a >= mod){
        a -= mod;
    }
    if(a < 0){
        a += mod;
    }
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

int f(int x, int y){
    if(y == 0){
        return 0;
    }
    return x / y;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mod;

    ll s = 0;

    ll s1 = 0;
    u[1] = 1;
    u[2] = mod - 1;
    dp[1] = 1;

    for(int i = 1; i < n; i++){
        ll x = s1;
        up(s, u[i]);
        u[i] = 0;
        up(x, s);
        for(int j = i; j <= n; j += i){
            up(u[j], mul(x, j / i));
            up(u[j + i], -mul(x, j / i));
        }
        for(int j = i + 1; j <= n; j += i + 1){
            up(u[j], -mul(x, j / (i + 1)));
            up(u[j + i + 1], mul(x, j / (i + 1)));
        }
        up(s, u[i]);
        up(s1, x);
    }

    up(s, u[n]);
    up(s1, s);
    cout << s1 << "\n";

    return 0;
}
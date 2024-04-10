#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 4e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll poww(ll x , ll y){
    ll ans = 1;
    for(; y ; y >>= 1 , x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

ll n , ans , fact[MAXN] , inv[MAXN] , A[MAXN];

ll C(ll n , ll r){
    if(r < 0 || r > n)  return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
    for(int i = MAXN - 2 ; i >= 0 ; i--){
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    cin >> n;
    for(int i = 0 ; i <= n ; i++){
        cin >> A[i];
        ans += C(A[i] + i , i + 1);
    }
    cout << ans % MOD << endl;

    return 0;
}
/*

*/
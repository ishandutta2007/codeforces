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

const ll MAXN = (1 << 19) + 10;
const ll LOG = 19;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x , ll y){
    ll ans = 1;
    for( ; y ; y >>= 1 , x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

ll n , fact[MAXN] , inv[MAXN] , A[MAXN] , B[MAXN] , C[MAXN] , ans[MAXN] , rev[MAXN] , INV[MAXN];

void NTT(ll A[] , int inv){
    for(int i = 1 ; i < (1 << LOG) ; i++){
        rev[i] = ((rev[(i >> 1)] >> 1) | ((i & 1) << (LOG - 1)));
        if(rev[i] < i){
            swap(A[i] , A[rev[i]]);
        }
    }
    for(int i = 1 ; i < (1 << LOG) ; i *= 2){
        ll wn = poww(5 , MOD / 2 / i);
        if(inv) wn = poww(wn , MOD - 2);
        for(int j = 0 ; j < (1 << LOG) ; j += i * 2){
            ll w = 1;
            for(int k = j ; k < j + i ; k++){
                ll v = A[k] , u = A[k + i] * w % MOD;
                A[k] = (v + u) % MOD;
                A[k + i] = (v + MOD - u) % MOD;
                w = w * wn % MOD;
            }
        }
    }
    if(inv){
        ll invn = poww((1 << LOG) , MOD - 2);
        for(int i = 0 ; i < (1 << LOG) ; i++){
            A[i] = A[i] * invn % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = INV[1] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
    for(int i = 2 ; i < MAXN ; i++){
        INV[i] = (MOD - MOD / i) * INV[MOD % i] % MOD;
    }
    inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
    for(int i = MAXN - 2 ; i >= 0 ; i--){
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    cin >> n;
    for(int i = n / 2 ; i + 1 < n ; i++){
        A[i] = fact[n - i - 2];
    }
    for(int i = 0 ; i <= n ; i++){
        B[i] = inv[i];
    }

    NTT(A , 0);
    NTT(B , 0);
    for(int i = 0 ; i < (1 << LOG) ; i++){
        C[i] = (A[i] * B[i]) % MOD;
    }
    NTT(C , 1);
    ans[1] = fact[n - 1];
    for(int i = 2 ; i <= (n + 1) / 2 ; i++){
        ans[i] = C[n - i] * fact[n - i] % MOD * (i - 1) % MOD;
    }
    ll cur = 0;
    for(int i = n ; i >= 1 ; i--){
        ans[i] = (ans[i] + MOD - cur * INV[i] % MOD) % MOD;
        cur = (cur + ans[i]) % MOD;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << sep;
    }

    return 0;
}
/*

*/
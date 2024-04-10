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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x, ll y){
    ll ans = 1;
    for(; y; y >>= 1, x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

ll q , n , A[MAXN] , ps[MAXN] , pw2[MAXN] , fact[MAXN] , inv[MAXN];
map<ll , ll> cntL , cntR;

ll C(ll r , ll n){
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = pw2[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        fact[i] = fact[i - 1] * i % MOD;
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }
    inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
    for(int i = MAXN - 2 ; i >= 0 ; i--){
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    cin >> q;
    while(q--){
        cin >> n;
        cntL.clear(); cntR.clear();
        ll sum = 0;
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
            sum += A[i];
        }
        partial_sum(A , A + n + 5 , ps);
        for(int i = 1 ; i < n ; i++){
            cntL[ps[i]]++;
            cntR[sum - ps[i]]++;
        }
        ll ans = 1;
        for(auto &i : cntL){
            ll val = i.X;
            if(val * 2 > sum)   continue;
            if(val * 2 == sum){
                ans = ans * pw2[cntL[val]] % MOD;
            }
            else{
                ans = ans * C(cntL[val] , cntL[val] + cntR[val]) % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/
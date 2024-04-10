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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
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

ll q , n , fact[MAXN] , inv[MAXN] , cnt[MAXN] , sum[MAXN] , tot[MAXN] , INV[MAXN];

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
    INV[1] = 1;
    for(int i = 2 ; i < MAXN ; i++){
        INV[i] = (MOD - MOD / i) * INV[MOD % i] % MOD;
    }

    cin >> q;
    while(q--){
        cin >> n;
        fill(cnt , cnt + n + 5 , 0);
        fill(sum , sum + n + 5 , 0);
        fill(tot , tot + n + 5 , 0);
        ll g = 0;
        for(int i = 0 ; i < n ; i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int> values;
        for(int i = 1 ; i <= n ; i++){
            if(cnt[i] > 0){
                g = __gcd(g , cnt[i]);
                values.push_back(i);
            }
        }
        if(SZ(values) == 1){
            cout << 1 << endl;
            continue;
        }
        for(int i = 1 ; i <= n ; i++){
            if(g % i != 0)  continue;
            ll invx = 1;
            for(int j : values){
                invx = invx * inv[cnt[j] / i] % MOD;
            }
            tot[i] = fact[n / i] * invx % MOD;
            for(int j : values){
                int c = cnt[j] / i;
                sum[i] = (sum[i] + fact[n / i - 2] * invx % MOD * c % MOD * (c - 1) % MOD * n) % MOD;
            }
        }
        for(int i = n ; i >= 1 ; i--){
            for(int j = i * 2 ; j <= n ; j += i){
                tot[i] = (tot[i] + MOD - tot[j]) % MOD;
                sum[i] = (sum[i] + MOD - sum[j]) % MOD;
            }
        }
        ll ans = 0 , ways = 0;
        for(int i = 1 ; i <= n ; i++){
            tot[i] = tot[i] * INV[n / i] % MOD;
            sum[i] = sum[i] * INV[n / i] % MOD;
            ans += sum[i];
            ways += tot[i];
        }
        ans %= MOD;
        ways %= MOD;
        cout << (n + MOD - ans * poww(ways , MOD - 2) % MOD) % MOD << endl;
    }

    return 0;
}
/*

*/
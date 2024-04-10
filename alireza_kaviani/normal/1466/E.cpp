#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 62;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , n , A[MAXN] , cnt[LOG];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        fill(cnt , cnt + LOG , 0);
        ll ans = 0 , sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i];
            for(int j = 0 ; j < LOG ; j++){
                if(A[i] & (1ll << j)){
                    cnt[j]++;
                }
            }
           // cout << A[i] % MOD << endl;
            sum += A[i] % MOD;
        }
        //cout << sum << endl;
        sum %= MOD;
        for(int i = 0 ; i < n ; i++){
            ll cur = 0 , val = (A[i] % MOD * n + sum) % MOD;
            for(int j = 0 ; j < LOG ; j++){
                if(A[i] & (1ll << j)){
                    cur += (1ll << j) % MOD * cnt[j] % MOD;
                }
            }
            cur %= MOD;
            val = (val + MOD - cur) % MOD;
            // cout << cur << sep << val << endl;
            ans += cur * val % MOD;
            /*ll res = 0;
            for(int j = 0 ; j < n ; j++){
                res += (A[i] & A[j]) % MOD;
            }
            cout << res % MOD << sep << cur << endl;*/
        }
        cout << ans % MOD << endl;
    }

    return 0;
}
/*

*/
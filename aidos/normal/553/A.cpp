#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int k;
int fact[1000100];
int mod = 1000000007;
ll binpow(ll x, int k){
    if( k==0) return 1;
    if(k % 2 == 1) return binpow(x, k-1) * x % mod;
    return binpow(x * x % mod, k/2);
}
ll getC(int n, int k){
    return fact[n] * 1ll * binpow(fact[n-k] * 1ll * fact[k] % mod, mod-2) % mod;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    fact[0] = 1;
    for(int i = 1; i < 1000010; i++)
        fact[i] = (fact[i-1] * 1ll * i) % mod;
    cin >> k;
    ll ans = 1;
    int sum = 0;
    for(int i = 0, x; i < k; i++){
        cin >> x;
        ans=(ans * getC(sum + x - 1, x-1)) % mod;
        sum += x;
    }
    cout << ans << endl;






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
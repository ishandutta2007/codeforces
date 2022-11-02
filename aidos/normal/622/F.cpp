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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1 << 29) - 1;
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
ll f[maxn];
ll nf[maxn];
ll a[maxn];
ll y[maxn];
ll binpow(ll x, ll m) {
	if(m == 0) return 1;
	if(m % 2 == 1) {
		return binpow(x, m-1) * x % mod;
	}
	return binpow(x * x % mod, m/2);
}
void solve(){
	cin >> n >> k;
	if(k == 0) {
		cout << n << "\n";
		return;
	}
	f[0] = 1;
	for(int i = 1; i <= k + 2; i++) {
		f[i] = f[i-1] * i % mod;
	}
	for(int i=1; i <= k + 2; i++) {
		y[i] = (y[i-1] + binpow(i, k)) % mod;
	}
	if(n <= k + 2) {
		cout << y[n] << "\n";
		return;
	}
	nf[0] = 1;
	for(int i = 1; i <= k + 2; i++) {
		nf[i] = nf[i-1]*(mod-i) % mod;
	}
	ll F = 1;
	for(int i = 1; i <= k + 2; i++) {
		F = F * (n-i) % mod;
	}
	ll ans = 0;
	for(int i = 1; i <= k + 2; i++) {
		ll cur = F * binpow(n-i, mod-2) % mod;
		ll q = f[i-1] * nf[k+2-i] % mod;
		ans = (ans + cur * y[i] % mod * binpow(q, mod-2)) % mod;
	}
	cout << ans << "\n";

}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}
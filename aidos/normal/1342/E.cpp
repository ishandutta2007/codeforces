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
const int maxn = (int)2e5 + 10; //maximum + 10
const int mod = (int) 998244353;
using namespace std;
ll n, k;
ll f[maxn];
ll binpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return binpow(x, y-1) * x % mod;
	return binpow(x * x % mod, y/2);
}
ll C(int n, int k) {
	return f[n] * binpow(f[n-k] * f[k] % mod, mod-2) % mod;
}
void solve(){
	cin >> n >> k;
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		f[i] = f[i-1] * i % mod;
	}
	if(k >= n) {
		cout << 0 << "\n";
		return;
	}
	k = n - k;
	
	ll ans = 0;
	for(int i = k; i >= 1; i--) {
		if(i % 2 == k % 2) ans = (ans + C(k, i) * binpow(i, n) % mod) % mod;
		else ans = (ans+mod- C(k, i) * binpow(i, n) % mod) % mod;
	}
	ans = (ans + mod) % mod;
	ans = C(n, k) * ans % mod;
	cout << (ans * (1+(n!=k))) % mod << "\n";
}
int main () {
	int t = 1;
    //scanf("%d", &t);
    for(int i=1; i<=t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}
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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, k;
int dp[15050];
int fact[15050];
int rev[15050];
int mod = 1000 * 1000 * 1000 + 7;
int binpow(int x, int y){
	int res = 1;
	while(y > 0){
		if(y & 1) res = (res * 1ll * x) % mod;
		x = (x * 1ll * x) % mod;
		y >>= 1;
	}
	return res;
}

int C(int n, int k){
	return fact[n] * 1ll * rev[k] % mod * rev[n-k] % mod;
}
int step[15050];
void solve(){
	
	cin >> n >> k;
	fact[0] = 1;
	for(int i = 1; i <= 13010; i++)
		fact[i] = fact[i-1] * 1ll * i % mod;
	for(int i = 0; i <= 13010; i++){
		rev[i] = binpow(fact[i], mod-2);
		step[i] = binpow(i, k);
	}	
	if(n <= 2 * k + 2){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = (ans + C(n, i) * 1ll * step[i]) % mod;
		}
		//cerr<<-1<<endl;
		cout << ans << endl;
		return;
	}
	int ans = 0;
	for(int i = k; i <= 2*k+2; i++){
		int res = 0;
		for(int j = 1; j <= i; j++){
			res = (res + C(i, j) * 1ll * step[j]) % mod;
		}
		int p = 1;
		res = (res * 1ll * binpow(binpow(2, mod-2), i-k)) % mod;
		for(int j = k; j <= 2*k+2; j++){
			if(i !=j)
				p = (p * 1ll * (n - j)) % mod;
		}
		int q = 1;
		for(int j = k; j <= 2*k+2; j++){
			if(i != j)
				q = (q * 1ll * (i - j)) % mod;
		}
		if(q < 0) q += mod;

		ans = (ans + res * 1ll * p % mod * binpow(q, mod-2)) % mod;
	}
	cout << ans * 1ll * (binpow(2, n - k)) % mod << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
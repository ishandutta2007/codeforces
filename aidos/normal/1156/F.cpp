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
const int mod = 998244353;
using namespace std;
ll cnt[5050];
int a[5050];
ll binpow(ll x, ll y){
	ll res = 1;
	while(y > 0) {
		if(y&1) res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}
int n;
ll dp[5050];
ll S[5050];
ll D[5050];
ll rev[5050];
int C;
void solve(){
	scanf("%d", &n);
	for(int i=0; i< n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 0; i <= n; i++) {
		rev[i] = binpow(i, mod-2);
	}
	ll ans = 0;
	int sum = 0;
	for(int i = n; i >= 1; i--){
		if(cnt[i] == 0) continue;
		sum += cnt[i];
		for(int j = max(sum-1, 1); j <= n-1; j++) {
			dp[j] = S[j - 1] * 1ll * rev[j] % mod;
		}
		for(int j = max(sum-1, 1); j <= n-1; j++){
			dp[j] = (dp[j] + (cnt[i]-1) * 1ll * rev[j]) % mod;
		}
		ans = (ans + (cnt[i]) * 1ll * dp[n-1]) % mod;
		for(int j = max(sum-1, 1); j <= n-1; j++) {
			S[j] = (S[j] + dp[j] * 1ll * cnt[i]) % mod;
		}
		
		
	}
	cout << ans * rev[n] % mod << "\n";
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
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

int n;
int cnt[1000100];
ll dp[1000100];
int f[1000100];
int rev[1000100];
int mod = 1000 * 1000 * 1000 + 7;
int binpow(ll x, int t){
	ll res = 1;
	while(t > 0){
		if(t & 1) res = (res * x) % mod;
		x = x * x % mod;
		t >>= 1;
	}
	return res;
}
void solve(){
	f[0] = 1;
	for(int i = 1; i<1000010; i++){
		f[i] = f[i-1] * 2 % mod;
		rev[i] = binpow(i, mod-2);
	}
	scanf("%d", &n);

	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}
	ll ans = 0;
	for(int i = 1000000; i > 1; i--){
		int t=cnt[i];
		for(int j = i + i; j <= 1000000; j+=i){
			dp[i] = (dp[i] - (dp[j] * rev[j] % mod) + mod) % mod;
			t += cnt[j];
		}
		dp[i] = (dp[i] + f[t-1]*1ll * t) % mod;
		dp[i] = dp[i] * i % mod;
		ans += dp[i]; 
	}
	cout << ans % mod << endl;	

}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
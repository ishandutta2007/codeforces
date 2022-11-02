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
int dp[1000100][21];
int lp[1000100];
int x, y;
int mod=1000000007;
int f[1000100];
int r[1000100];
int pw[1000100];
int binpow(int g, int s){
	ll res = 1;
	while(s>0){
		if(s&1){
			res = (res*g) % mod;
		}
		s>>=1;
		g = (g*1ll*g) % mod;
	}
	return res;
}
int get(int pos,int sum){
	if(pos == 0) return sum == 0;
	int &res = dp[pos][sum];
	if(res != -1) return res;
	res = 0;
	for(int i = 0; i <= sum; i++){
		res += get(pos-1, sum-i);
		if(res >= mod) res-=mod;
	}
	return res;
}

void solve(){
	scanf("%d%d", &x, &y);
	ll ans = 1;
	while(x>1){
		int p = lp[x];
		int cnt = 0;
		while(x % p == 0){
			x/=p;
			++cnt;
		}
		ans = (ans*get(y, cnt)) % mod;
	}
	ans =(ans*pw[y-1]) %mod;
	printf("%d\n", (int)ans);
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    for(int i = 2; i*i<= 1000010; i++){
    	if(lp[i] == 0){
    		lp[i] = i;
    		for(int j = i * i; j <= 1000010; j+=i){
    			if(lp[j] == 0){
    				lp[j] = i;
    			}
    		}
    	}
    }
    f[0] = 1;
    r[0] = 1; 
    pw[0] = 1;
    for(ll i=1; i <= 1000010; i++){
    	if(lp[i]==0) lp[i] = i;
    	f[i] = f[i-1] * i % mod;
    	r[i] = binpow(f[i], mod-2);
    	pw[i] = (pw[i-1] + pw[i-1]) % mod;
    }
    memset(dp, -1, sizeof dp);
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
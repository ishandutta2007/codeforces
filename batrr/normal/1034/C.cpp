#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;

vector<int> g[N];
int n, ans, dp[N], cnt[N], cur[N];
ll s, a[N];
ll dfs(int v){
	for(auto to:g[v]){
		dfs(to);
		a[v] += a[to];
	}
}
int main(){    
	scanf("%d",&n);        
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s += a[i];	
	}
	for(int i = 2; i <= n; i++){
		int x;
		scanf("%d", &x);
		g[x].pb(i);
	}
	dfs(1);
	
	for(int i = 1; i <= n; i++){
		a[i] = __gcd(s,a[i]);
	    if(s/a[i] < N)
        	cnt[s/a[i]]++;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j+=i)
			cur[j] += cnt[i];
	for(int i = n; i >= 1; i--){
		if(s % i == 0){
			if(cur[i] != i)
				continue;
			dp[i] = 1;
			if(i > 1){
				for(int j = i + i; j <= n; j += i){
					dp[i] += dp[j];
					if(dp[i] >= mod)
						dp[i] -= mod;
				}
			}
			ans += dp[i];
			if(ans >= mod)
				ans -= mod;
		}
	}
	printf("%d",ans);
	return 0;
}
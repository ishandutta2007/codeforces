#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, K = 110, mod = 998244353, inf = (int)1e9;

void add(int &a, int b){
	a += b;
	if(a >= mod)
		a -= mod;
}
void del(int &a, int b){
	a -= b;
	if(a < 0)
		a += mod;
}

int n, k, m, a[N], lst[K], s[N];
int dp[K][N];
int get(int j, int i){
	if(i - m + 1 >= lst[j]){
		int q = i - m + 1;
		if(a[q] == -1){
			if(q == 1){
				return 1;
			}else{
				return (s[q - 1] - dp[j][q - 1] + mod) % mod;
			}
		}else{
			if(a[q] == j){
				if(q == 1)
					return 1;
				else
					return (s[q - 1] - dp[j][q - 1] + mod) % mod;
			}else{
				return 0;
			}
		}
	}else
		return 0;
}
int main(){
	scanf("%d%d%d", &n, &k, &m);
	if(m == 1){
		printf("0");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > 0)
			a[i]--;
	}
	for(int j = 0; j < k; j++)
		if(a[1] == j || a[1] == -1){	
			dp[j][1] = 1;
			lst[j] = 1;
			s[1]++;
		}else{
			dp[j][1] = 0;
			lst[j] = inf;
		}
	for(int i = 2; i <= n; i++){
		if(a[i] >= 0){
			for(int j = 0; j < k; j++)
            	add(dp[a[i]][i], dp[j][i - 1]);
			del(dp[a[i]][i], get(a[i], i));
			if(lst[a[i]] == inf)
				lst[a[i]] = i;
			for(int j = 0; j < k; j++)
				if(j != a[i])
					lst[j] = inf;	
		}else{
			int sum = 0;
			for(int j = 0; j < k; j++)
				add(sum, dp[j][i - 1]);
			for(int j = 0; j < k; j++)
				dp[j][i] = (sum - get(j, i) + mod) % mod;
			for(int j = 0; j < k; j++)
				if(lst[j] == inf)
					lst[j] = i;	
		}
		for(int j = 0; j < k; j++)
			add(s[i], dp[j][i]);
	}

	int ans = 0;
	for(int j = 0; j < k; j++)
		add(ans, dp[j][n]);
	printf("%d\n", ans);
	return 0;
}
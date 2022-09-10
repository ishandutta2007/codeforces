#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 101;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, k;
int dp[N][N];
pair <PII, int> in[N];

int solve(int id){
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j < k; ++j)
			dp[i][j] = -MX;
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; ++i){
		if(i == id){
			for(int j = 0; j < k; ++j)
				dp[i][j] = dp[i - 1][j];
			continue;
		}
		
		dp[i][0] = dp[i - 1][0];
		for(int j = 1; j < k; ++j)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + in[i].st.nd - (k - j) * in[i].st.st);
	}
	
	int ans = dp[n][k - 1];
	for(int i = 1; i <= n; ++i)
		if(i != id)
			ans += (k - 1) * in[i].st.st;
		else
			ans += (k - 1) * in[i].st.st + in[i].st.nd;
	return ans;
}

void restore(int id){
	solve(id);
	vector <bool> picked(n + 1, false);
	
	int p = n, v = k - 1;
	while(p){
		p--;
		if(dp[p][v] == dp[p + 1][v])
			continue;
		
		picked[p + 1] = true;
		v--;
	}
	
	printf("%d\n", k + 2 * (n - k));
	for(int i = 1; i <= n; ++i)
		if(picked[i])
			printf("%d ", in[i].nd);
	
	for(int i = 1; i <= n; ++i)
		if(!picked[i] && i != id)
			printf("%d %d ", in[i].nd, -in[i].nd);
	printf("%d\n", in[id].nd);
}

void solve(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &in[i].st.nd, &in[i].st.st);
		in[i].nd = i;
	}

	sort(in + 1, in + n + 1);
	
	int ans = 0, opt = 1;
	for(int i = 1; i <= n; ++i){
		int tmp = solve(i);
		if(tmp > ans)
			ans = tmp, opt = i;
	}
	
	fprintf(stderr, "ans = %d\n", ans);
	restore(opt);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
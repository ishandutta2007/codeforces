#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int K = 107;
const int N = 1e5 + 7;
const int MX = 1e9 + 7;

int n, k;
int l[N], r[N];

int mn[N][2];
int dp[K][N][2];

void find(int t, int far, int s){
	deque <PII> Q;
	for(int i = 0; i <= n; ++i){
		while(!Q.empty()){
			if(Q.back().st < dp[t][i][s])
				break;
			Q.pop_back();
		}
		
		Q.push_back({dp[t][i][s], i});
		if(Q.front().nd < i - far)
			Q.pop_front();
		mn[i][s] = Q.front().st;
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		dp[0][i][0] = dp[0][i][1] = MX;
	dp[0][0][1] = MX;
	
	for(int i = 1; i <= k; ++i)
		scanf("%d %d", &l[i], &r[i]);
	
	if(r[k] < 2 * n){
		l[k + 1] = r[k + 1] = 2 * n;
		++k;
	}
	
	for(int i = 1; i <= k; ++i){
		find(i - 1, r[i] - l[i], 0);
		find(i - 1, r[i] - l[i], 1);

		for(int j = 0; j <= n; ++j){
			dp[i][j][0] = r[i] - r[i - 1] <= j ? dp[i - 1][j - r[i] + r[i - 1]][0] : MX;
			dp[i][j][0] = min(dp[i][j][0], min(mn[j][1] + 1, j >= l[i] - r[i - 1] ? mn[j - l[i] + r[i - 1]][0] + 2 : MX));
			
			dp[i][j][1] = min(dp[i - 1][j][1], min(mn[j][1] + 2, l[i] - r[i - 1] <= j ? mn[j - l[i] + r[i - 1]][0] + 1 : MX));
//			printf("%d %d -> %d %d\n", i, j, dp[i][j][0], dp[i][j][1]);
		}
	}
	
	int res = min(dp[k][n][0], dp[k][n][1]);
	if(res == MX)
		puts("Hungry");
	else
		printf("Full\n%d\n", res);
	return 0;
}
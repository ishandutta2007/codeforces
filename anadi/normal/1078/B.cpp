#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 107;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int res;
int val[N];

int cnt[N];
bitset <N> dp[N][N * N];

void countDp(vector <int> &cur, int v, int cntv){
	int m = v * cntv;
	for(int i = 1; i <= (int)cur.size(); ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j].reset();
	
	dp[0][0][0] = true;
	for(int i = 0; i < (int)cur.size(); ++i){
		for(int j = 0; j + cur[i] <= m; ++j)
			dp[i + 1][j + cur[i]] |= (dp[i][j] << 1);
		for(int j = 0; j <= m; ++j)
			dp[i + 1][j] |= dp[i][j];
	}
	
	for(int i = 1; i <= cntv; ++i)
		if(!dp[cur.size()][i * v][i])
			res = max(res, i);
		else
			break;
}

int main(){
	scanf("%d", &n); int diff = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &val[i]);
		cnt[val[i]]++;
		
		if(cnt[val[i]] == 1)
			++diff;
	}
	
	if(diff <= 2){
		printf("%d\n", n);
		return 0;
	}
	
	for(int i = 1; i <= 100; ++i){
		if(cnt[i] == 0)
			continue;
		
		vector <int> t;
		for(int j = 1; j <= n; ++j)
			if(val[j] != i)
				t.push_back(val[j]);		
		countDp(t, i, cnt[i]);
	}
	
	printf("%d\n", res);
	return 0;
}
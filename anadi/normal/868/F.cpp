#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e12 + 9LL;

int n, m;
int tab[N];
int cur[N];
LL dp[21][N];
queue <pair <PII, PII> > Q, Q2;

void DC(int row){
	Q.push({{0, n}, {1, n}});
	while(!Q.empty()){
		LL res = 0LL;
		int curP = n + 1, curK = n + 1;

		while(!Q.empty()){
			pair <PII, PII> xd = Q.front();
			Q.pop();
			
			int p = xd.st.st, k = xd.st.nd, s = xd.nd.st, e = xd.nd.nd;
			int m = (s + e) / 2;
			
			int mini = min(m, k + 1);
			while(mini < curP){
				--curP;
				res += cur[tab[curP]];
				cur[tab[curP]]++;
			}
			
			while(m + 1 < curK){
				--curK;
				cur[tab[curK]]--;
				res -= cur[tab[curK]];
			}
			
			int m2 = mini - 1;
			LL best = res + dp[row - 1][m2];
			
			while(curP > p + 1){
				--curP;
				res += cur[tab[curP]];
				cur[tab[curP]]++;
				if(res + dp[row - 1][curP - 1] < best){
					best = res + dp[row - 1][curP - 1];
					m2 = curP - 1;
				}
			}
			
			dp[row][m] = best;
			if(m < e)
				Q2.push({{m2, k}, {m + 1, e}});
			if(s < m)
				Q2.push({{p, m2}, {s, m - 1}});
		}
		
		Q = Q2;
		while(!Q2.empty())
			Q2.pop();
		
		for(int i = 0; i <= n; ++i)
			cur[i] = 0;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		dp[0][i] = INF;
	}
	
	dp[0][0] = 0LL;
	for(int i = 1; i <= m; ++i)
		DC(i);
	
	printf("%lld\n", dp[m][n]);
	return 0;
}
//an awesome problem.
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int absv(int x)
{
	return x < 0 ? -x : x;
}
int n, x[2005], G[2005][2005];
char S[2005][2005];
bool dfs(int v, int c)
{
	if(x[v] == !c) return false;
	else if(x[v] == c) return true;
	x[v] = c;
	rep(i, n + 1) if(G[v][i] != -1 && !dfs(i, c ^ G[v][i])) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%s", S[i]);
	if(n & 1) {
		printf("NONE\n"); return 0;
	}
	
	rep(i, n + 1) rep(j, n + 1) G[i][j] = -1;
	for(int i = 0; i < n; i += 2) G[i][i + 2] = G[i + 2][i] = 1;
	rep(i, n) rep(j, n) if(S[i][j] != '.') {
		int val = (S[i][j] == 'S') ^ (i & 1) ^ (j & 1);
		int d0 = absv(i - j), d1 = absv(i + j - n + 1);
		if(G[d0][n - d1] == !val) {
			printf("NONE\n"); return 0;
		}
		G[d0][n - d1] = G[n - d1][d0] = val; 
	}
	
	rep(i, n + 1) x[i] = -1;
	int cnt = 0;
	rep(i, n + 1) if(x[i] == -1) {
		cnt ++;
		if(!dfs(i, 0)) {
			printf("NONE\n"); return 0;
		}
	}
	if(cnt >= 2) printf("MULTIPLE\n");
	else {
		rep(i, n) rep(j, n) S[i][j] = (i & 1) ^ (j & 1) ^ x[absv(i - j)] ^ x[n - absv(i + j - n + 1)] ? 'S' : 'G';
		printf("UNIQUE\n");
		rep(i, n) printf("%s\n", S[i]);
	}
	return 0;
}
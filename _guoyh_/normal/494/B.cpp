# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int MOD = 1000000007;
int n, m;
int fail[MAXN];
int g[MAXN];
char s[MAXN], t[MAXN];
int main(){
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	fail[0] = -1;
	for (int i = 1; i <= m; i++){
		int p = fail[i - 1];
		while (p != -1 && t[p + 1] != t[i]) p = fail[p];
		fail[i] = p + 1;
	}
	int nw = 0, ans = 0;
	int lft = 0, sum1 = 0, sum2 = 0;
	g[0] = 1;
	for (int i = 1; i <= n; i++){
		while (nw != -1 && t[nw + 1] != s[i]) nw = fail[nw];
		nw++;
		if (i >= m){
			sum1 = (sum1 + g[i - m]) % MOD;
			sum2 = (sum2 + sum1) % MOD;
		}
		if (nw == m){
			g[i] = sum2;
			nw = fail[nw];
		} else if (i > 1) g[i] = g[i - 1];
		// printf("f %d %d %d %d\n", i, g[i], sum1, sum2);
	}
	for (int i = 1; i <= n; i++) ans = (ans + g[i]) % MOD;
	printf("%d\n", ans);
	return 0;
}
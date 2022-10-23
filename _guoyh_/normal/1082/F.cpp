# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 505;
const int MAXK = 11;
int n, k;
char s[MAXN];
struct Trie{
	int nxt[10];
} t[MAXN];
int cnt[MAXN], dep[MAXN];
int rt = 1, tsz = 1;
int f[MAXN][MAXN][MAXK], f1[MAXN][MAXN][MAXK];
void insert(int nm){
	int sz = strlen(s + 1);
	int p = rt;
	for (int i = 1; i <= sz; i++){
		if (!t[p].nxt[s[i] - '0']){
			t[p].nxt[s[i] - '0'] = ++tsz;
			dep[t[p].nxt[s[i] - '0']] = dep[p] + 1;
		}
		p = t[p].nxt[s[i] - '0'];
		cnt[p] += nm;
	}
}
void dfs(int nw){
	// printf("dfs %d %d\n", nw, cnt[nw]);
	for (int i = 0; i <= dep[nw]; i++) f[nw][i][0] = 0;
	for (int i = 0; i < 10; i++){
		int nxtn = t[nw].nxt[i];
		if (!nxtn) continue;
		dfs(nxtn);
		memset(f1[nw], 0, sizeof(f1[nw]));
		for (int j = 0; j <= dep[nw]; j++){
			for (int l = 0; l <= k; l++){
				for (int u = 0; u <= l; u++){
					f1[nw][j][l] = max(f1[nw][j][l], f[nw][j][l - u] + f[nxtn][j][u]);
					if (u >= 1) f1[nw][j][l] = max(f1[nw][j][l], f[nw][j][l - u] + f[nxtn][dep[nxtn]][u - 1] + cnt[nxtn] * (dep[nxtn] - j));
				}
			}
		}
		memcpy(f[nw], f1[nw], sizeof(f1[nw]));
		// printf("f %d:\n", nw);
		// for (int j = 0; j <= dep[nw]; j++){
		// 	for (int l = 0; l <= k; l++){
		// 		printf("%d ", f[nw][j][l]);
		// 	}
		// 	putchar('\n');
		// }
		// putchar('\n');
	}
}
int main(){
	scanf("%d%d", &n, &k);
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int u;
		scanf("%s%d", s + 1, &u);
		ans += u * strlen(s + 1);
		insert(u);
	}
	dfs(rt);
	ans -= f[rt][0][k];
	printf("%d\n", ans);
	return 0;
}
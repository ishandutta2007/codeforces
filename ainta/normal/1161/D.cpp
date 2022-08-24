#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, chk[2020], vis[2020];
char p[1010];
long long Mod = 998244353, res = 0;
vector<int>E[2010], L[2010];
void Add_Edge(int a, int b, int c) {
	E[a].push_back(b);
	E[b].push_back(a);
	L[a].push_back(c);
	L[b].push_back(c);
}
void DFS(int a, int col) {
	vis[a] = 1;
	chk[a] = col;
	for (int i = 0; i < E[a].size(); i++) {
		if(!vis[E[a][i]])DFS(E[a][i], col^L[a][i]);
	}
}
void Do() {
	int i;
	for (i = 1; i <= n + m; i++) {
		E[i].clear(), L[i].clear();
		vis[i] = 0;
		chk[i] = -1;
	}
	for (i = 1; i <= n; i++) {
		if (p[i] != '?') {
			if (i > m) {
				chk[i] = p[i] - '0';
			}
			else {
				Add_Edge(i, n + i, p[i] - '0');
			}
		}
	}
	chk[n + m] = 1;
	for (i = 1; i <= n; i++) {
		Add_Edge(i, n + 1 - i, 0);
	}
	for (i = 1; i <= m; i++) {
		Add_Edge(n + i, n + (m + 1 - i), 0);
	}
	for (i = 1; i <= n + m; i++) {
		if (chk[i]!=-1 && !vis[i]) {
			DFS(i, chk[i]);
		}
	}
	long long s = 1;
	for (i = 1; i <= n + m; i++) {
		if (!vis[i]) {
			DFS(i, 0);
			s = s * 2 % Mod;
		}
	}
	for (i = 1; i <= n + m; i++) {
		for (int j = 0; j < E[i].size(); j++) {
			if (chk[i] ^ chk[E[i][j]] != L[i][j])s = 0;
		}
		if (i > m && i <= n && p[i] != '?' && chk[i] != p[i] - '0')s = 0;
	}
	if (chk[n + m] != 1)s = 0;
	res = (res + s) % Mod;
}
int main() {
	int i;
	scanf("%s", p+1);
	for (i = 1; p[i]; i++);
	n = i-1;
	for (i = 1; i <= n / 2; i++)swap(p[i], p[n + 1 - i]);
	for (m = 1; m < n; m++) {
		Do();
	}
	printf("%lld\n", res);
}
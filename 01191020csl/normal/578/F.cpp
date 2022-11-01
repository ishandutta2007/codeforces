#include<bits/stdc++.h>
using namespace std;
char c[101][101];
int fa[12000], id[12001], p;
int getfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
void link(int x, int y) {
	x = getfa(x), y = getfa(y);
	if (x == y) {
		puts("0");
		exit(0);
	}
	fa[x] = y;
}
vector<int> v1, v2;
int power(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = 1ll * ans * a % p;
		a = 1ll * a * a % p;
		n >>= 1;
	}
	return ans;
}
int mat[201][201];
int det(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			mat[i][j] = (mat[i][j]%p+p)%p;
	int neg = 1;
	for (int i = 1; i <= n; i++) {
		int q = 0;
		for (int j = i; j <= n; j++)
			if (mat[j][i]) q = j;
		if (!q) return 0;
		if (q != i) {
			neg *= -1;
			for (int j = i; j <= n; j++)
				swap(mat[i][j], mat[q][j]);
		}
		int tmp = power(mat[i][i], p-2);
		for (int j = i + 1; j <= n; j++) {
			int t = 1ll*mat[j][i]*tmp%p;
			for (int k = i; k <= n; k++) mat[j][k] = (p+mat[j][k]-1ll*t*mat[i][k]%p)%p;
		}
	}
	int ans = neg==1?1:p-1;
	for (int i = 1; i <= n; i++) ans = 1ll * ans * mat[i][i] % p;
	return ans;
}
int main() {
	int n, m;
	cin >> n >> m >> p;
	for (int i = 0; i < (n+1)*(m+1); i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char ch = getchar();
			while (ch != '/' && ch != '\\' && ch != '*') ch = getchar();
			if (ch == '/') link(j*(n+1)+i-1, (j-1)*(n+1)+i);
			if (ch == '\\') link(j*(n+1)+i, (j-1)*(n+1)+i-1);
			c[i][j] = ch;
		}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (getfa(j*(n+1)+i) == j*(n+1)+i) {
				if ((i + j) & 1) v1.push_back(j*(n+1)+i);
				else v2.push_back(j*(n+1)+i);
			}
	int ans = 0;
	if (v1.size() <= 201) {
		for (int i = 0; i < v1.size(); i++) id[v1[i]] = i;
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (c[i][j] == '*') {
					int u, v;
					if ((i+j)&1) u = j*(n+1)+i, v = (j-1)*(n+1)+i-1;
					else u = j*(n+1)+i-1, v = (j-1)*(n+1)+i;
					u = id[getfa(u)], v = id[getfa(v)];
					++mat[u][u], ++mat[v][v], --mat[u][v], --mat[v][u];
				}
		ans += det(v1.size()-1);
	}
	if (v2.size() <= 201) {
		for (int i = 0; i < v2.size(); i++) id[v2[i]] = i;
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (c[i][j] == '*') {
					int u, v;
					if ((i+j)&1) u = j*(n+1)+i-1, v = (j-1)*(n+1)+i;
					else u = j*(n+1)+i, v = (j-1)*(n+1)+i-1;
					u = id[getfa(u)], v = id[getfa(v)];
					++mat[u][u], ++mat[v][v], --mat[u][v], --mat[v][u];
				}
		ans += det(v2.size()-1);
	}
	cout << ans % p << endl;
}
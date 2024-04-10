#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pi;

const int N = 15;
const int M = 11005;
const int mo1 = 317503;
const int mo2 = 1000000007;
const int BAS = 2333;
const int P = 3000005;

int n, m, k, Hash[N], bel[N], tot, matching[M][N][2], temp_matching[N][2], bin[N];
LL ans, jc[N];
vector<int> e[N];
int ls[mo1], nx[P], key[P], tot_hash;
bool vis[N], trans[N][N][N][N], f[5005][N];

void add_hash(int *Hash) {
	int h1 = 0, h2 = 0;
	for (int i = 1; i <= n; i++) {
		h1 = ((LL)h1 * BAS + Hash[i]) % mo1;
		h2 = ((LL)h2 * BAS + Hash[i]) % mo2;
	}
	for (int i = ls[h1]; i; i = nx[i])
		if (key[i] == h2) return;
	key[++tot_hash] = h2; nx[tot_hash] = ls[h1]; ls[h1] = tot_hash;
}

bool find_hash(int *Hash) {
	int h1 = 0, h2 = 0;
	for (int i = 1; i <= n; i++) {
		h1 = ((LL)h1 * BAS + Hash[i]) % mo1;
		h2 = ((LL)h2 * BAS + Hash[i]) % mo2;
	}
	for (int i = ls[h1]; i; i = nx[i])
		if (key[i] == h2) return 1;
	return 0;
}

void dfs_matching(int x) {
	if (x > n / 2) {
		tot++;
		for (int i = 1; i <= n / 2; i++) {
			matching[tot][i][0] = temp_matching[i][0];
			matching[tot][i][1] = temp_matching[i][1];
		}
		return;
	}
	int u;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			u = i; vis[i] = 1;
			break;
		}
	temp_matching[x][0] = u;
	for (int j = u + 1; j <= n; j++)
		if (!vis[j]) {
			temp_matching[x][1] = j;
			vis[j] = 1;
			dfs_matching(x + 1);
			vis[j] = 0;
		}
	vis[u] = 0;
}

void dfs_half_divide(int x, int y, int id) {
	if (x > n / 2) {
		for (int i = 1; i <= n / 2; i++)
			Hash[matching[id][i][0]] = Hash[matching[id][i][1]] = bel[i];
		add_hash(Hash);
		return;
	}
	for (int i = 1; i <= y; i++) {
		bel[x] = i;
		dfs_half_divide(x + 1, y, id);
	}
	bel[x] = y + 1;
	dfs_half_divide(x + 1, y + 1, id);
}

void dfs_divide(int x, int y) {
	if (x > n) {
		for (int i = 1; i <= n; i++) Hash[i] = bel[i];
		if (find_hash(Hash) && y <= k)
			ans += jc[k] / jc[k - y];
		return;
	}
	for (int i = 1; i <= y; i++) {
		bel[x] = i;
		dfs_divide(x + 1, y);
	}
	bel[x] = y + 1;
	dfs_divide(x + 1, y + 1);
}

void pre_matching() {
	bin[0] = 1;
	for (int i = 1; i <= n; i++) bin[i] = bin[i - 1] * 2;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			for (int i : e[u])
				for (int j : e[v])
					trans[u][v][i][j] = 1;
	for (int i = 1; i <= tot; i++) {
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= n / 2; j++) f[bin[j - 1]][j] = 1;
		for (int j = 1; j < bin[n / 2] - 1; j++)
			for (int k = 1; k <= n / 2; k++) {
				int u = matching[i][k][0], v = matching[i][k][1];
				if (f[j][k]) {
					for (int l = 1; l <= n / 2; l++)
						if (!(j & bin[l - 1])) {
							int p = matching[i][l][0], q = matching[i][l][1];
							f[j + bin[l - 1]][l] |= trans[u][v][p][q] | trans[u][v][q][p];
						}
				}
			}
		bool tag = 0;
		for (int j = 1; j <= n / 2; j++) {
			int u = matching[i][j][0], v = matching[i][j][1];
			tag |= f[bin[n / 2] - 1][j] & trans[u][v][v][u];
		}
		if (tag) dfs_half_divide(1, 0, i);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		e[x].push_back(y); e[y].push_back(x);
	}
	jc[0] = 1;
	for (int i = 1; i <= k; i++) jc[i] = jc[i - 1] * i;
	dfs_matching(1);
	pre_matching();
	dfs_divide(1, 0);
	printf("%lld\n", ans);
	return 0;
}
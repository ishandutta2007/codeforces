#include <bits/stdc++.h> ///////////// why remote judge die???????????
using namespace std;
#define ld long double
const int N = 50 + 5;
int n, sz[N];
ld fc[N], f[N][N];
vector <int> e[N];
void dfs(int id, int fa) {
	for(int it : e[id]) if(it != fa) dfs(it, id);
	static ld g[N], h[N];
	memset(g, 0, sizeof(g));
	sz[id] = 0;
	g[0] = 1;
	for(int it : e[id])
		if(it != fa) {
			memset(h, 0, sizeof(h));
			for(int i = 0; i <= sz[it] + 1; i++) {
				ld coef = f[it][i] / fc[i] / fc[sz[it] + 1 - i];
				for(int j = 0; j <= sz[id]; j++) h[i + j] += coef * g[j];
			}
			memcpy(g, h, sizeof(g));
			sz[id] += sz[it] + 1;
		}
	// cout << id << endl;
	// for(int i = 0; i <= sz[id]; i++) cout << g[i] << " "; cout << endl;
	if(!fa) printf("%.12Lf\n", g[0]);
	else {
		for(int i = 0; i <= sz[id]; i++) g[i] = g[i] * fc[i] * fc[sz[id] - i];
		// cout << id << endl;
		// for(int i = 0; i <= sz[id]; i++) cout << g[i] << " "; cout << endl;
		for(int j = 0; j <= sz[id] + 1; j++)
			for(int k = 1; k <= sz[id] + 1; k++)
				if(k <= j) f[id][j] += g[j - 1]; // j -> j - 1
				else f[id][j] += g[k - 1] / 2;
	}
	// for(int i = 0; i <= sz[id] + 1; i++) cerr << "chk " << id << " " << i << " " << f[id][i] << endl;
}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n;
	for(int i = fc[0] = 1; i <= n; i++) fc[i] = fc[i - 1] * i;
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	for(int i = 1; i <= n; i++) memset(f, 0, sizeof(f)), dfs(i, 0);
	return 0;
}

/*
2022/4/28
start thinking at 9:10

.
.
 DP.
, .
, ,  cnt, (1 / 2) ^ cnt.
, .
 f_{i, j, k}  i ,  j  i  k.
.
.
n ^ 5, .

ycx :  j,  (1 / 2) ^ j . 1 / 2 .
 n ^ 4.
 n ^ 3? .

.
f_{i, j}  i ,  > j  LIS  e  sum (1 / 2) ^ e.
<= j .
 f_{u, i} * f_{v, j} * C(i + j, j) * C(sz[u] + sz[v] - i - j, sz[u] - j) -> f_{x, i + j}.
 sz , .
,  n ^ 2.
? .
 f_son ,  g.
 f_{id, j},  id  k.
 k <= j,  k ,  g_{j - 1},  1  k  <= j ,
 <= j  j - 1,  j - 1 .
 k > j,  k  1 / 2 ,  < k ,  g_{k - 1} / 2.
 g_0, .

finish debugging at 14:19
*/
# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 3051;
const int MAXV = MAXN;
const int MAXE = MAXN * 20;
struct Edge{
	int t, c;
	int nxt;
} g[MAXE * 2];
int n, gsz = 1;
int a[MAXN], b[MAXN];
int fte[MAXV], curE[MAXV];
int dep[MAXV];
int flag[MAXN];
void addedge(int x, int y, int z){
	// printf("addedge %d %d %d\n", x, y, z);
	g[++gsz] = (Edge){y, z, fte[x]};
	fte[x] = gsz;
	g[++gsz] = (Edge){x, 0, fte[y]};
	fte[y] = gsz;
}
bool bfs(int S, int T){
	queue <int> q;
	memset(dep, -1, sizeof(dep));
	q.push(S);
	dep[S] = 1;
	while (!q.empty()){
		int nw = q.front();
		q.pop();
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			if (dep[nxtn] != -1 || g[i].c == 0) continue;
			dep[nxtn] = dep[nw] + 1;
			q.push(nxtn);
		}
	}
	return dep[T] != -1;
}
int dfs(int nw, int mxf, int T){
	if (nw == T) return mxf;
	if (mxf == 0) return 0;
	int df = 0;
	for (int &i = curE[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (dep[nxtn] != dep[nw] + 1 || g[i].c == 0) continue;
		int nwf = dfs(nxtn, min(mxf - df, g[i].c), T);
		if (nwf == 0) dep[nxtn] = -1;
		g[i].c -= nwf;
		g[i ^ 1].c += nwf;
		df += nwf;
		if (df == mxf) break;
	}
	return df;
}
int dinic(int S, int T){
	int ans = 0;
	while (bfs(S, T)){
		memcpy(curE, fte, sizeof(fte));
		ans += dfs(S, 1e9, T);
	}
	return ans;
}
int main(){
	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	int S = 0, T = n + 1;
	for (int i = 1; i <= n; i++){
		if (b[i] > 0){
			ans += b[i];
			addedge(i, T, b[i]);
		} else addedge(S, i, -b[i]);
		for (int j = i - 1; j >= 1; j--){
			if (a[i] % a[j] == 0 && flag[a[j]] != i){
				flag[a[j]] = i;
				addedge(j, i, 1e9);
			}
		}
	}
	printf("%d\n", ans - dinic(S, T));
	return 0;
}
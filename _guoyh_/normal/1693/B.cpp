# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200051;
int t, n;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int fa[MAXN];
ll al[MAXN], ar[MAXN];
ll f1[MAXN], f2[MAXN];
void dfs(int nw){
	f1[nw] = f2[nw] = 0;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		dfs(nxtn);
		f1[nw] += f1[nxtn];
		f2[nw] += f2[nxtn];
	}
	f2[nw] = min(f2[nw], ar[nw]);
	if (f2[nw] < al[nw]){
		f1[nw]++;
		f2[nw] = ar[nw];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		gsz = 0;
		for (int i = 1; i <= n; i++){
			fte[i] = 0;
			f1[i] = f2[i] = 0;
		}
		for (int i = 2; i <= n; i++){
			cin >> fa[i];
			addedge(fa[i], i);
		}
		for (int i = 1; i <= n; i++) cin >> al[i] >> ar[i];
		dfs(1);
		cout << f1[1] << '\n';
	}
	return 0;
}
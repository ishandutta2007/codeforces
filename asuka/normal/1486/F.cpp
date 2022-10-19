#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3e5 + 5;
#define pii pair<int, int>
vector<int> E[N];
int n, dep[N], st[N][20], fa[N], L[N], R[N], tr[N], dft;
struct node{
	int x, y, a, b, lca;
}q[N];
int cmp(node A, node B){
	if(dep[A.lca] != dep[B.lca]) return dep[A.lca] < dep[B.lca];
	return A.lca < B.lca;
}
void dfs(int a, int pre){
	L[a] = ++dft;
	for(int b: E[a]){
		if(b != pre){
			st[b][0] = fa[b] = a;
			dep[b] = dep[a] + 1;
			dfs(b, a);
		}
	}
	R[a] = dft;
}
void build_st(){
	for(int i = 1; i < 20; i++)
		for(int j = 1; j <= n; j++) st[j][i] = st[st[j][i - 1]][i - 1];
}
int Lca(int a, int b){
	if(dep[b] > dep[a]) swap(a, b);
	int di = dep[a] - dep[b];
	for(int i = 19; i >= 0; i--) if(di >> i & 1) a = st[a][i];
	if(a == b) return a;
	for(int i = 19; i >= 0; i--) if(st[a][i] != st[b][i]) a = st[a][i], b = st[b][i];
	return st[a][0];
}
int up(int a, int x){
	if(x <= 0) return a;
	for(int i = 19; i >= 0; i--) if(x >> i & 1) a = st[a][i];
	return a;
}
void add(int i, int x){
	for(; i <= n; i += i & -i) tr[i] += x;
}
int query(int i){
	int s = 0;
	for(; i > 0; i -= i & -i) s += tr[i];
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dfs(1, 0);
	build_st();
	int m;
	cin >> m;
	for(int i = 1, x, y; i <= m; i++){
		cin >> x >> y;
		int lca = Lca(x, y);
		int a = up(x, dep[x] - dep[lca] - 1), b = up(y, dep[y] - dep[lca] - 1);
		if(a == lca) a = -1;
		if(b == lca) b = -1;
		if(a > b) swap(a, b), swap(x, y);
		q[i] = {x, y, a, b, lca};
	}
	sort(q + 1, q + m + 1, cmp);
	LL ans1 = 0, ans2 = 0;
	for(int i = 1, j = 1; i <= m; i++, j = i){
		map<pii, int> f;
		map<int, int> cnt;
		while(q[j + 1].lca == q[i].lca) j++;
		int lca = q[i].lca;
		for(int k = i, x, y, a, b; k <= j; k++){
			x = q[k].x, y = q[k].y, a = q[k].a, b = q[k].b;
			ans1 += k - i - cnt[a] - cnt[b] + f[make_pair(a, b)];
			if(a != -1) cnt[a]++;
			if(b != -1) cnt[b]++;
			if(a != -1 && b != -1) f[make_pair(a, b)]++;
			ans2 += query(R[lca]) - query(L[lca] - 1);
			if(a != -1) ans2 -= query(R[a]) - query(L[a] - 1);
			if(b != -1) ans2 -= query(R[b]) - query(L[b] - 1);
		}
		for(int k = i; k <= j; k++) add(L[q[k].x], 1), add(L[q[k].y], 1);
		i = j;
	}
	cout << ans1 + ans2 << '\n';
	return 0;
}
# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1000051;
struct Query{
	int l, r, id;
	bool operator < (const Query &o) const{
		return l > o.l;
	}
} q[MAXN];
struct BIT{
	# define lowbit(x) ((x) & (-(x)))
	int c[MAXN];
	void add(int pos, int nm){
		for (int i = pos; i < MAXN; i += lowbit(i)) c[i] += nm;
	}
	int getsum(int pos){
		int ans = 0;
		for (int i = pos; i; i -= lowbit(i)) ans += c[i];
		return ans;
	}
} t;
int n, Q;
int a[MAXN];
int ans[MAXN];
int nxt[MAXN], last[MAXN];
int st[MAXN], ed[MAXN];
vector <int> adj[MAXN];
int main(){
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++){
		if (a[i] > n) continue;
		adj[a[i]].push_back(i);
		if (adj[a[i]].size() >= a[i]) st[adj[a[i]][(int)adj[a[i]].size() - a[i]]] = i;
		if (adj[a[i]].size() >= a[i] + 1) ed[adj[a[i]][adj[a[	i]].size() - a[i] - 1]] = i;
	}
	for (int i = n; i >= 1; i--){
		if (a[i] > n) continue;
		nxt[i] = last[a[i]];
		last[a[i]] = i;
	}
	for (int i = 1; i <= Q; i++){
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + Q + 1);
	q[0].l = n + 1;
	for (int i = 1; i <= Q; i++){
		for (int j = q[i - 1].l - 1; j >= q[i].l; j--){
			if (a[j] > n) continue;
			if (nxt[j]){
				if (st[nxt[j]]) t.add(st[nxt[j]], -1);
				if (ed[nxt[j]]) t.add(ed[nxt[j]], 1);
			}
			if (st[j]) t.add(st[j], 1);
			if (ed[j]) t.add(ed[j], -1);
		}
		ans[q[i].id] = t.getsum(q[i].r);
	}
	for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
	return 0;
}
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
const int PR = 998244353;
struct Edge{
	int t, nxt;
} g[NR * 2];
int t;
int n, m, gsz;
ll cnt1, cnt2, ans;
int fte[NR];
bool vis[NR], col[NR];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % PR;
		x = x * x % PR;
		y >>= 1;
	}
	return ans;
}
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
bool dfs(int nw){
	cnt2++;
	cnt1 += col[nw];
	vis[nw] = true;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (vis[nxtn]){
			if (col[nxtn] == col[nw]) return false;
			else continue;
		}
		col[nxtn] = col[nw] ^ 1;
		if (!dfs(nxtn)) return false;
	}
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		gsz = 0;
		ans = 1;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) fte[i] = 0;
		for (int i = 1; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		bool suc = true;
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			cnt1 = cnt2 = 0;
			col[i] = 1;
			if (!dfs(i)){
				suc = false;
				break;
			}
			ans = ans * (pwr(2, cnt1) + pwr(2, cnt2 - cnt1) % PR) % PR;
		}
		if (!suc) printf("0\n");
		else printf("%lld\n", ans);
	}
	return 0;
}
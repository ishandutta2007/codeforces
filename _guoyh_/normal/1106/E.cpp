# include <queue>
# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int MAXM = 205;
struct Packet{
	int s, t, d;
	ll w;
	bool operator < (const Packet &o) const{
		if (w != o.w) return w < o.w;
		else return d < o.d;
	}
};
ll ans = 1e18;
int n, m, k;
ll f[MAXN][MAXM];
vector <Packet> adj[MAXN];
priority_queue <Packet> q;
void update(ll &a, ll b){
	if (b < a) a = b;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++){
		Packet a;
		scanf("%d%d%d%lld", &a.s, &a.t, &a.d, &a.w);
		adj[a.s].push_back(a);
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 0; i < n; i++){
		while (!q.empty() && q.top().t < i + 1) q.pop();
		for (int j = 0; j < adj[i + 1].size(); j++) q.push(adj[i + 1][j]);
		for (int j = 0; j <= m; j++){
			if (!q.empty()) update(f[q.top().d][j], f[i][j] + q.top().w);
			else update(f[i + 1][j], f[i][j]);
			if (j < m) update(f[i + 1][j + 1], f[i][j]);
			// printf("f %d %d %lld\n", i, j, f[i][j]);
		}
	}
	for (int i = 0; i <= m; i++) update(ans, f[n][i]);
	printf("%lld\n", ans);
	return 0;
}
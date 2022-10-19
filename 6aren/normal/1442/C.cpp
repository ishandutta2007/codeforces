#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define x first
#define y second
#define pb push_back
#define all(s) (s).begin(), (s).end()
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;
const int MOD = 998244353;

int n, m;
vector<int> g[N];
vector<int> rg[N];
int d[N][21];
bool done[N][21];

int power(int x, int y) {
	if (y == 0)
		return 1;

	int res = 1;
	while (y) {
		if (y % 2)
			res = res * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return res;
}


void dijkstra() {

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 21; j++)
			d[i][j] = 1e18;
	}

	d[1][0] = 0;



	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, {1, 0}});

	while (!pq.empty()) {
		iii foo = pq.top();
		pq.pop();

		int dis = foo.x;
		int u = foo.y.x;
		int nrev = foo.y.y;

		if (done[u][nrev])
			continue;
		done[u][nrev] = 1;

		// tranpose

		if (nrev < 20) {
			if (d[u][nrev + 1] > dis + (1 << nrev)) {
				d[u][nrev + 1] = dis + (1 << nrev);
				pq.push({d[u][nrev + 1], {u, nrev + 1}});
			}
		}

		// 
		if (nrev % 2 == 0) {
			for (int e : g[u]) {
				if (d[e][nrev] > dis + 1) {
					d[e][nrev] = dis + 1;
					pq.push({d[e][nrev], {e, nrev}});
				}
			}
		} else {
			for (int e : rg[u]) {
				if (d[e][nrev] > dis + 1) {
					d[e][nrev] = dis + 1;
					pq.push({d[e][nrev], {e, nrev}});
				}
			}
		}

	}

	int ans = 1e18;

	for (int i = 0; i < 21; i++) 
		ans = min(ans, d[n][i]);

	if (ans != 1e18) {
		cout << ans % MOD << '\n';
		exit(0);
	}
}

int dis[N][2];
bool done2[N][2];

void dijsktra2() {

	for (int i = 1; i <= n; i++) 
		dis[i][0] = dis[i][1] = 1e18;
	dis[1][0] = 0;

	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, {1, 0}});

	while (!pq.empty()) {
		iii foo = pq.top();
		pq.pop();
		int u = foo.y.x;
		int nrev = foo.y.y;
		int di = foo.x;

		if (done2[u][nrev])
			continue;
		done2[u][nrev] = 1;

		// tranpose

		
		if (dis[u][1 - nrev] > di + 1e12) {
			dis[u][1 - nrev] = di + 1e12;
			pq.push({dis[u][1 - nrev], {u, 1 - nrev}});
		}

		// 
		if (nrev % 2 == 0) {
			for (int e : g[u]) {
				if (dis[e][nrev] > di + 1) {
					dis[e][nrev] = di + 1;
					pq.push({dis[e][nrev], {e, nrev}});
				}
			}
		} else {
			for (int e : rg[u]) {
				if (dis[e][nrev] > di + 1) {
					dis[e][nrev] = di + 1;
					pq.push({dis[e][nrev], {e, nrev}});
				}
			}
		}

	}

	int ans = min(dis[n][0], dis[n][1]);

	int ans1 = ans / ((int) 1e12);
	int ans2 = ans % ((int) 1e12);

	int res = ((power(2, ans1) + MOD - 1) + ans2) % MOD;

	cout << res << endl;


}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	dijkstra();

	// for (int i = 1; i <= n; i++) 
	// 	g[0].push_back(i);
	// dfs(0);

	dijsktra2();

	return 0;
}
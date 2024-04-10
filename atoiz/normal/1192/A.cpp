/*input
13 2
4 6
3 5
3 4
3 3
4 2
5 2
6 2
7 3
7 4
7 5
6 6
5 4
5 5



8 2
3 5
5 3
3 3
5 5
2 4
6 4
4 2
4 4
 
8 2
0 2
1 2
1 0
0 0
2 1
2 0
0 1
2 2
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
 
using namespace std;
 
using pii = pair<int, int>;
#define r first
#define c second
 
const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MAXN = 150007, MAXV = MAXN * 9, INF = 1e9 + 7;
const int EXT = -1, ALIVE = 1, IN = 0;
int G[MAXV][8], type[MAXV], T, N, V, P[MAXV], inComp[MAXV];
pii C[MAXV], orC[MAXN];
bool peri[MAXV], inq[MAXV];
priority_queue<int> pq;
vector<int> ans;
bool vis[MAXV];
 
bool comp(int i, int j) { return C[i] < C[j]; }
 
int search(pii p)
{
	int lo = 1, hi = V;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (C[P[mid]] < p) lo = mid + 1;
		else hi = mid;
	}
	if (C[P[lo]] == p) return P[lo];
	return 0;
}
 
int calc(int u)
{
	int cnt = 0;
	vector<int> vec;
	for (int d = 0; d < 8; d += 2) {
		cnt += ((type[G[u][d]] == EXT) && (type[G[u][(d + 1) & 7]] != EXT || type[G[u][(d + 2) & 7]] != EXT));
		if (type[G[u][d]] == IN && (type[G[u][(d + 1) & 7]] == ALIVE || type[G[u][(d + 2) & 7]] == ALIVE)) {
			vec.push_back(inComp[G[u][d]]);
		}
	}

	sort(vec.begin(), vec.end());
	for (int i = 1; i < (int) vec.size(); ++i) {
		if (vec[i - 1] == vec[i]) return INF;
	}

	return cnt;
}
 
void dfs(int u)
{
	vis[u] = 1;
	for (int d = 0; d < 8; ++d) {
		int v = G[u][d];
		if (!vis[v] && type[v] == ALIVE) dfs(v);
	}
}
 
void fillExt(int u)
{
	type[u] = EXT;
 
	for (int d = 0; d < 8; d += 2) {
		if (type[G[u][d]] == ALIVE) {
			peri[G[u][d]] = 1;
			if (!inq[G[u][d]] && calc(G[u][d]) <= 1) {
				inq[G[u][d]] = 1;
				pq.push(G[u][d]);	
			}
		} else if (type[G[u][d]] == IN) {
			fillExt(G[u][d]);
		}
	}
 
	for (int d = 0; d < 8; ++d) {
		if (type[G[u][d]] == ALIVE && peri[G[u][d]] && !inq[G[u][d]] && calc(G[u][d]) <= 1) {
			inq[G[u][d]] = 1;
			pq.push(G[u][d]);
		}
	}
}

void fillIn(int u)
{
	for (int d = 0; d < 8; d += 2) {
		if (type[G[u][d]] == IN && inComp[G[u][d]] == 0) {
			inComp[G[u][d]] = inComp[u];
			fillIn(G[u][d]);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> T; V = N;
	for (int i = 1; i <= N; ++i) cin >> C[i].r >> C[i].c;
	for (int i = 0; i < N; ++i) orC[i] = C[i + 1];
	sort(orC, orC + N); orC[N] = {INF, INF};
 
	vector<pair<int, int>> all(N * 8);
	for (int i = 1; i <= N; ++i) {
		for (int d = 0; d < 8; ++d) {
			all[(i - 1) * 8 + d] = {C[i].r + dr[d], C[i].c + dc[d]};
		}
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (auto a : all) {
		if (*lower_bound(orC, orC + N, a) != a) {
			C[++V] = a;
		}
	}
 
	for (int u = 1; u <= V; ++u) P[u] = u;
	// for (int u = 1; u <= V; ++u) cout << C[u].r << ' ' << C[u].c << endl;
	sort(P + 1, P + V + 1, comp);
 
	for (int u = 1; u <= V; ++u) {
		for (int d = 0; d < 8; ++d) {
			G[u][d] = search({C[u].r + dr[d], C[u].c + dc[d]});
		}
	}
 
	type[0] = EXT;
	for (int u = 1; u <= N; ++u) type[u] = ALIVE;
	for (int u = N + 1; u <= V; ++u) type[u] = IN;
	for (int u = N + 1; u <= V; ++u) {
		if (inComp[u] == 0) {
			inComp[u] = u;
			fillIn(u);
		}
	}
 
	dfs(1);
	for (int u = 1; u <= N; ++u) if (!vis[u]) return cout << "NO" << endl, 0;
 
	fillExt(N + 1);
	ans.reserve(N);
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		assert(type[u] == ALIVE && peri[u]);
		if (calc(u) > 1) {
			inq[u] = 0;
			continue;
		}
		ans.push_back(u);
		fillExt(u);
	}
 
	assert((int) ans.size() == N);
	cout << "YES\n";
	for (int i = (int) ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << '\n';
	}
}
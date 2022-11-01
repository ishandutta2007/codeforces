#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)

using Pii = pair<int, int>;

int dist[3000][3000];
vector<int> e[3000];
vector<Pii> v[3000], iv[3000];

int main() {
	int n, m; cin >> n >> m;
	FOR(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
	}
	FOR(s, n) {
		memset(dist[s], 0x2f, sizeof(int) * 3000);
		dist[s][s] = 0;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto to : e[v]) {
				if (dist[s][to] > dist[s][v] + 1) {
					dist[s][to] = dist[s][v] + 1;
					q.push(to);
				}
			}
		}
		FOR(i, n) if (dist[s][i] == 0x2f2f2f2f) dist[s][i] = -dist[s][i];
	}

	FOR(a, n) {
		FOR(i, n) if(dist[a][i] > 0) v[a].push_back(Pii(dist[a][i], i));
		FOR(i, n) if (dist[a][i] > 0) iv[i].push_back(Pii(dist[a][i], a));
	}
	FOR(a, n) {
		sort(v[a].rbegin(), v[a].rend());
		sort(iv[a].rbegin(), iv[a].rend());
	}

	int mxd = 0;
	tuple<int, int, int, int> ans;
	FOR(a, n) FOR(b, n) {
		if (a == b) continue;
		FOR(i, 10) {
			if (i >= sz(iv[a])) break;
			Pii sc = iv[a][i];
			if (sc.second == a || sc.second == b) continue;
			FOR(j, 10) {
				if (j >= sz(v[b])) break;
				Pii sd = v[b][j];
				if (sd.second == a || sd.second == b || sd.second == sc.second) continue;
				int cost = sc.first + dist[a][b] + sd.first;
				if (mxd < cost) {
					mxd = cost;
					ans = make_tuple(sc.second, a, b, sd.second);
				}
			}
		}
	}
	int a, b, c, d; tie(a, b, c, d) = ans;
	printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);

}
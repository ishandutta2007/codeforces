#include <iostream>
#include <vector>
#include <set>
using namespace std;


const int N = 100 * 1000 + 5;
const long long inf = 1e15;

vector <int> adj[N];
long long d[N];
long long d2[N];
set <pair <int, int> > s;
vector <int> vec[N];
int wt[N], st[N], ed[N], w[N];
bool mark[N];


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> st[i] >> ed[i] >> wt[i];
		adj[st[i]].push_back(i);
	}
	fill(d + 2, d + n + 1, inf);
	s.insert({0, 1});
	while (s.size()) {
		int v = (*s.begin()).second;
		s.erase(s.begin());
		for (auto x : adj[v]) {
			int u = ed[x], w = wt[x];
			if (d[v] + w < d[u]) {
				s.erase({d[u], u});
				d[u] = d[v] + w;
				s.insert({d[u], u});
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << "73 " << i << " " << d[i] << endl;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (auto x : adj[i]) {
//			wt[x] += d[st[x]] - d[ed[x]];
//		}
//	}
	for (int i = 1; i <= m; i++) {
		w[i] = wt[i] + d[st[i]] - d[ed[i]];
	}
	for (int ii = 0; ii < q; ii++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int v;
			cin >> v;
			if (d[v] >= inf)
				cout << "-1\n";
			else
				cout << d[v] << '\n';

		}
		else {
			int c;
			cin >> c;
			for (int i = 0; i < c; i++) {
				int x;
				cin >> x;
				wt[x]++;
				w[x]++;
			}
			fill(mark, mark + n + 1, false);
			vec[0].push_back(1);
			fill(d2 + 2, d2 + n + 1, inf);
			for (int i = 0; i <= c; i++) {
				int t = 0;
				while (t < vec[i].size()) {
					int v = vec[i][t];
					if (!mark[v]) {
					//	cout << "72 " << v << " " << i << endl;
						d2[v] = i;
						mark[v] = true;
						for (auto x : adj[v]) {
						//	cout << "74 " << v << " " << x << " " << d2[v] + w[x] << endl;
							if (d2[v] + w[x] <= c) {
								vec[d2[v] + w[x]].push_back(ed[x]);
							}
						}
					}
					t++;
				}
				vec[i].clear();
			}
			for (int i = 1; i <= n; i++) {
				d[i] += d2[i];
			//	cout << "71 " << d2[i] << endl; 
			}
			for (int i = 1; i <= m; i++) {
				w[i] = wt[i] + d[st[i]] - d[ed[i]];
			}			
		}

	}

	return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;


const int N = 100 * 1000 + 5;

bool df[N];
//vector <int> frt;
vector <int> adj[N];
bool mark[N];
double f[N];
double a[N];
set <pair <double, int> > s;
int ord[N];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	fill(f, f + n + 1, 1);
	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		df[v] = true;
		f[v] = -1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	//	if (!df[u]) {
	//		cnt[v]++;
	//	}
	//	else {
	//		cnt[u]++;
	//	}
	}
	for (int i = 1; i <= n; i++) {
		s.insert({f[i], i});
	}
	int ansfor = 1;
	while (s.size()) {
		int v = (*s.begin()).second;
		a[s.size()] = f[v];
		ord[v] = s.size();
	//	cout << "73 " << v << " " << f[v] << endl;
		if (f[v] > a[ansfor]) {
			ansfor = s.size();
		}
		s.erase(s.begin());
		mark[v] = true;
		for (auto u : adj[v]) {
			if (!mark[u]) {
				s.erase({f[u], u});
				f[u] -= (double) 1 / adj[u].size();
				s.insert({f[u], u});
			}
		}
			
	}
	cout << ansfor << endl;
	for (int i = 1; i <= n; i++) {
		if (ord[i] <= ansfor) {
			cout << i << " ";
		}
	}
	return 0;
}
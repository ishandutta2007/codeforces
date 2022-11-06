#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;
vector<pair<int, int>> adj[MxN + 9];
int is[MxN + 9];

void f() {

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 3 * n; ++i) {
		adj[i].clear();
		is[i] = false;
	}

	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		adj[v].push_back( { i, u });
	}

	vector<int> matching;

	for (int i = 1; i <= 3 * n; i++) {
		is[i] = true;
		for (const pair<int, int> &p : adj[i]) {
			const int x = p.second;
			if (is[x]) {
				is[x] = is[i] = false;
				matching.push_back(p.first);
				break;
			}
		}
	}

	if ((int) matching.size() >= n) {
		cout << "Matching\n";
		for (int i = 0; i < n; ++i)
			cout << matching[i] << " \n"[i == n - 1];
	} else {
		cout << "IndSet\n";
		int cnt = 0;
		for (int i = 1; cnt < n; ++i)
			if (is[i]) {
				cout << i << " \n"[cnt++ == n - 1];
				if (cnt == n)
					break;
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		f();
	return 0;
}
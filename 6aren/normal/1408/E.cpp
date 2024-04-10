#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

#define ii pair<int, int>
#define x first
#define y second

int a[N], b[N];
int n, m;
vector<pair<ii, int>> edges;
int p[2 * N];

int root(int x) {
	if (p[x] == x) return x;
	return (p[x] = root(p[x]));
}



int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= m; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) {
			int u;
			cin >> u;
			edges.push_back({{u, n + i}, a[i] + b[u]});
		}
	}

	for (int i = 1; i <= m + n; i++) 
		p[i] = i;

	sort(edges.begin(), edges.end(), [](pair<ii, int> u, pair<ii, int> v) {
		return u.y > v.y;
	});

	long long sum = 0;

	for (auto e : edges) 
		sum += e.y;

	long long ans = 0;

	for (auto e : edges) {
		int u = e.x.x;
		int v = e.x.y;

		u = root(u);
		v = root(v); 

		if (u != v) {
			ans += e.y;
			p[u] = v;
		}
	}

	cout << sum - ans << endl;



	return 0;
}
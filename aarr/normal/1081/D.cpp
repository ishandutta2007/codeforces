#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

int par[N], cnt[N];
pair <int, pair <int, int> > e[N];

int get_par(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get_par(par[v]);
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> e[i].second.first >> e[i].second.second >> e[i].first;
	}

	sort(e, e + m);
	for (int i = 0; i < m; i++) {
		int u = e[i].second.first, v = e[i].second.second, w = e[i].first;
		if (get_par(v) != get_par(u)) {
		//	cout << "73 " << v << " " << u << endl;
			cnt[get_par(v)] += cnt[get_par(u)];
			cnt[get_par(u)] = 0;
			par[get_par(u)] = get_par(v);
			if (cnt[get_par(v)] == k) {
				for (int j = 1; j <= k; j++) {
					cout << w << " ";
				}
				return 0;
			}
			
		}
	}
	return 0;
}
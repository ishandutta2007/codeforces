#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 100 * 1000 + 5;
const long long inf = 2e5;

int par[N];
int st[N];
int ed[N];
pair <pair <long long, int>, int> e[N];
bool mark[N];

int get_par(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get_par(par[v]);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> st[i] >> ed[i] >> e[i].first.first;
		e[i].first.first *= 2;
		e[i].second = i;
		if (ed[i] < st[i]) {
			swap(st[i], ed[i]);
		}
		e[i].first.second = -i;
	}
	sort(e, e + m);
	int dw = -inf, up = inf;
	while (up - dw > 1) {
		long long md = (dw + up) / 2;
		for (int i = 0; i < m; i++) {
			if (st[e[i].second] == 1) {
				e[i].first.first += md;
			}
		}
		sort(e, e + m);
		for (int i = 1; i <= n; i++) {
			par[i] = i;
		}
		int s = 0;
		for (int i = 0; i < m; i++) {
			int u = get_par(st[e[i].second]), v = get_par(ed[e[i].second]);
		//	cout << "53 " << e[i].second << endl;
			if (u != v) {
				par[u] = v;
				if (st[e[i].second] == 1) {
					s++;
				}
			}
		}
	/*	if (s == k) {
			cout << "23333333333333333 " << endl;
		}*/
	//	cout << "57 " << md << " " << s << endl;
		if (s > k) {
			dw = md;
		}
		else {
			up = md;
		}
		for (int i = 0; i < m; i++) {
			if (st[e[i].second] == 1) {
				e[i].first.first -= md;
			}
		}
		if (s == k) {
			break;
		}
	}
//	cout << "59 " << dw << endl;
//	dw += 1e-3;
	for (int i = 0; i < m; i++) {
		if (st[e[i].second] == 1) {
			e[i].first.first += up;
		}
	}
	sort(e, e + m);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	int s = 0, c = 0;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int u = get_par(st[e[i].second]), v = get_par(ed[e[i].second]);
		if (u != v) {
			c++;
			par[u] = v;
			if (st[e[i].second] == 1) {
				s++;
			}
			ans += e[i].first.first;
			if (st[e[i].second] == 1) {
				ans -= dw;
			}
			mark[e[i].second] = true;
		}
	}	
//	cout << "58 " << s << " " << c << endl;
	if (c != n - 1 || s != k) {
		cout << -1;
		return 0;
	}
//	cout << fixed << setprecision(0);
	cout << n - 1 << endl;
	for (int i = 0; i < m; i++) {
		if (mark[i]) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}
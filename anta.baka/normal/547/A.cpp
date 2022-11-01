#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int A = (int)1e6;

int g1[A];
int g2[A];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int m; cin >> m;
	int h1, a1; cin >> h1 >> a1;
	int x1, y1; cin >> x1 >> y1;
	int h2, a2; cin >> h2 >> a2;
	int x2, y2; cin >> x2 >> y2;
	for (int i = 0; i < m; i++) {
		g1[i] = (1LL * x1 * i + y1) % m;
		g2[i] = (1LL * x2 * i + y2) % m;
	}
	int steps = 0;
	for (int i = 0; i < m; i++) {
		steps++;
		h1 = g1[h1];
		h2 = g2[h2];
		if (h1 == a1 && h2 == a2) {
			return cout << steps, 0;
		}
	}
	for (int i = 0; i < m; i++) {
		steps++;
		h1 = g1[h1];
		h2 = g2[h2];
		if (h1 == a1 && h2 == a2) {
			return cout << steps, 0;
		}
		if (h1 == a1) {
			break;
		}
	}
	if (h1 != a1) {
		return cout << -1, 0;
	}
	int l1 = 0;
	do {
		l1++;
		h1 = g1[h1];
	} while (h1 != a1);
	int l2 = 0;
	int p = 0;
	int mem = h2;
	do {
		l2++;
		h2 = g2[h2];
		if (h2 == a2) {
			p = l2;
		}
	} while (h2 != mem);
	if (p == 0) {
		return cout << -1, 0;
	}
	for (int x = 1; x <= m; x++) {
		if (1LL * x * l1 >= p && (1LL * x * l1 - p) % l2 == 0) {
			return cout << steps + 1LL * x * l1, 0;
		}
	}
	cout << -1;
}
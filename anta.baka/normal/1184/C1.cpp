#include <iostream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const int inf = (int)1e9 + 100;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n; cin >> n; n = 4 * n + 1; vi x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) { // out
		int xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
		for (int j = 0; j < n; j++) if (i != j) {
			xmin = min(xmin, x[j]);
			ymin = min(ymin, y[j]);
			xmax = max(xmax, x[j]);
			ymax = max(ymax, y[j]);
		}
		if (xmax - xmin != ymax - ymin) continue;
		int cnt = 0;
		for (int j = 0; j < n; j++) if(i != j) cnt += (
			(x[j]==xmin && ymin <= y[j] && y[j] <= ymax) ||
			(x[j]==xmax && ymin <= y[j] && y[j] <= ymax) ||
			(y[j]==ymin && xmin <= x[j] && x[j] <= xmax) ||
			(y[j]==ymax && xmin <= x[j] && x[j] <= xmax)
			);
		int j = i;
		if (
			(x[j] == xmin && ymin <= y[j] && y[j] <= ymax) ||
			(x[j] == xmax && ymin <= y[j] && y[j] <= ymax) ||
			(y[j] == ymin && xmin <= x[j] && x[j] <= xmax) ||
			(y[j] == ymax && xmin <= x[j] && x[j] <= xmax)
			) continue;
		if (cnt == n - 1) return cout << x[i] << ' ' << y[i], 0;
	}
}
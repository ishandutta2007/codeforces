#include <bits/stdc++.h>

using namespace std;

const int M = 299345;

#define L 0
#define R 1

set<pair<int, int>> rod;
int n, m, x[M];

void read() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		rod.insert(make_pair(x[i], i));
	}
}

int run(int at, int dir, int len, int prev) {
	if (dir == R) {
		auto ptr = rod.lower_bound(make_pair(at + len + 1, 0));
		ptr--;
		int to = ptr->first;
		if (to == at) {
			if (prev != -1)
				return rod.lower_bound(make_pair(to, 0))->second;
			else 
				return run(at, L, len, at);
		}

		int ld = to - at;

		if (to == prev && len > (2 * ld)) {
			len %= (2 * ld);
			len += 2 * ld;
		}
		
		return run(to, L, len - ld, at);

	} else {


		auto prt = rod.lower_bound(make_pair(at - len, 0));

		int to = prt->first;

		if (to == at) {
			return prt->second;
		}

		int ld = at - to;

		if (to == prev && len > (2 * ld)) {
			len %= (2 * ld);
			len += 2 * ld;
		}

		return run(to, R, len - ld, at);
	}
}

void kill() {
	for (int i = 0; i < m; ++i) {
		int id, len;
		cin >> id >> len;
		int at = x[id];
		cout << run(at, R, len, -1) << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	read();
	kill();
	return 0;
}
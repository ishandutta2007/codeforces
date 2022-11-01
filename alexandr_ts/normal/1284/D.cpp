#include <iostream>
#include <cstdio>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

const int N = 1e5 + 10;

pair<int, int> a[2][N];

bool is_valid(pair<int, int>* a1, pair<int, int>* a2, int n) {
	vector<tuple<int, int, int>> a(2 * n);
	for (int i = 0; i < n; i++) {
		a[2 * i] = { a1[i].first, 0, i };
		a[2 * i + 1] = { a1[i].second, 1, i };
	}

	sort(begin(a), end(a));

	multiset<int> op_pos, cl_pos;
	
	for (int i = 0; i < 2 * n; i++) {
		int idx = get<2>(a[i]);
		if (get<1>(a[i])) {
			auto it = op_pos.find(a2[idx].first);
			op_pos.erase(it);
			auto it2 = cl_pos.find(a2[idx].second);
			cl_pos.erase(it2);
		}
		else {
			op_pos.insert(a2[idx].first);
			cl_pos.insert(a2[idx].second);
		}
		if (!op_pos.empty()) {
			if (*cl_pos.begin() < *prev(op_pos.end())) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[j][i].first >> a[j][i].second;
		}
	}

	if (is_valid(a[0], a[1], n) && is_valid(a[1], a[0], n)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
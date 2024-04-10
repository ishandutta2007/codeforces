#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<pair<int, int>> ans;

void swap(int a, int b, int n) {
	if(2 * abs(a - b) >= n) {
		ans.push_back({a, b});
	} else if(2 * abs(a - n) >= n && 2 * abs(b - n) >= n) {
		ans.push_back({a, n});
		ans.push_back({b, n});
		ans.push_back({a, n});
	} else if(2 * abs(a - 1) >= n && 2 * abs(b - 1) >= n) {
		ans.push_back({a, 1});
		ans.push_back({b, 1});
		ans.push_back({a, 1});
	} else if(2 * abs(a - n) >= n && 2 * abs(b - 1) >= n) {
		ans.push_back({a, n});
		ans.push_back({b, 1});
		ans.push_back({1, n});
		ans.push_back({a, n});
		ans.push_back({b, 1});
	} else {
		ans.push_back({a, 1});
		ans.push_back({b, n});
		ans.push_back({1, n});
		ans.push_back({a, 1});
		ans.push_back({b, n});
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int p[n];
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	vector<vector<int>> cycles;
	vector<int> used(n);
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			vector<int> cyc;
			int j = i;
			while(!used[j]) {
				used[j] = 1;
				cyc.push_back(j);
				j = p[j];
			}
			cycles.push_back(cyc);
		}
	}
	for(auto it: cycles) {
		for(size_t i = 1; i < it.size(); i++) {
			swap(it[0] + 1, it[i] + 1, n);
		}
	}
	cout << ans.size() << "\n";
	for(auto it: ans) {
		cout << it.first << ' ' << it.second << "\n";
	}
	return 0;
}
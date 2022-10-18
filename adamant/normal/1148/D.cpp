#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<pair<int, int>> best(vector<pair<int, int>> gg) {
	sort(begin(gg), end(gg));
	reverse(begin(gg), end(gg));
	return gg;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], b[n];
	vector<pair<int, int>> A, B;
	map<int, map<int, int>> prs;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		prs[a[i]][b[i]] = i + 1;
		if(a[i] < b[i]) {
			A.push_back({a[i], b[i]});
		} else {
			B.push_back({b[i], a[i]});
		}
	}
	auto AA = best(A);
	auto BB = best(B);
	if(AA.size() > BB.size()) {
		cout << AA.size() << endl;
		for(auto it: AA) {
			cout << prs[it.first][it.second] << ' ';
		}
	} else {
		cout << BB.size() << endl;
		reverse(begin(BB), end(BB));
		for(auto it: BB) {
			cout << prs[it.second][it.first] << ' ';
		}
	}
	return 0;
}
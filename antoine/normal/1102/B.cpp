#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	map<int, vector<int>> occ;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		occ[x].push_back(i);
		if (k < (int) occ[x].size()) {
			cout << "NO\n";
			exit(0);
		}
	}

	vector<int> ans(n);

	for (auto &&p : occ) {
		const vector<int> &v = p.second;
		for (int i = 0; i < (int)v.size(); ++i)
			ans[v[i]] = i;
	}

	set<int> unused;
	for (int i = 0; i < k; ++i)
		unused.insert(i);
	for (const int &x : ans)
		unused.erase(x);

	vector<int> used(k, false);
	for(int &x : ans)
		if(!used[x])
			used[x] = 1;
		else if(!unused.empty()) {
			x = *unused.begin();
			unused.erase(unused.begin());
		}


	cout << "YES\n";
	for (int x : ans)
		cout << x + 1 << ' ';
	return 0;
}
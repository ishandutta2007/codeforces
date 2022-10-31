#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = i;
	}
	b = a;
	sort(b.begin(), b.end());
	vector<int> tmp;
	vector<vector<int> > res;
	vector<int> used(n, 0);
	int k;
	for (int i = 0; i < n; i++) {
		k = i;
		tmp.clear();
		while (used[k] == 0) {
			tmp.push_back(k + 1);
			used[k] = 1;
			k = mp[b[k]];

		}
		if (tmp.size() > 0) {
			res.push_back(tmp);
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].size();
		for(int j = 0; j < res[i].size(); j++) {
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	return 0;
}
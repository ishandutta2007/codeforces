#include<bits/stdc++.h>

using namespace std;

set<int> S;
vector<int> a;

bool check(int a) {
	return (S.find(a) != S.end());
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		S.clear();
		a.clear();
		for (int i = 1; i <= n; i++) {
			int u;
			cin >> u;
			S.insert(u);
		}
		a.push_back(0);
		for (auto v : S) {
			a.push_back(v);
		} 
		int res = 0;
		for (int i = a.size() - 1; i > 0; i--) {
			int x = a[i], y = 0, z = 0;
			int id = i - 1;
			for (int j = id; j > 0; j--) {
				if (x % a[j] != 0) {
					y = a[j];
					id = j - 1;
					break;
				}
			}
			for (int j = id; j > 0; j--) {
				if (x % a[j] != 0 && y % a[j] != 0) {
					z = a[j];
					break;
				}
			}
			res = max(res, x + y +z);
		}
		cout << res << endl;
	}
	return 0;
}
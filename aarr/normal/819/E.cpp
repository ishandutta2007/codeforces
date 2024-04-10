#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > ans;

void solve(int n) {
	if (n == 3) {
		ans.push_back({1, 2, 3});
		ans.push_back({1, 2, 3});
		return;
	}
	if (n == 4) {
		ans.push_back({1, 2, 3, 4});
		ans.push_back({1, 3, 4, 2});
		ans.push_back({1, 3, 2, 4});
		return;
	}
	ans.push_back({n - 2, n - 1, n});
	ans.push_back({n - 2, n - 1, n});
	for (int i = 1; i < n - 3; i++) {
		ans.push_back({i, n - 1, i + 1, n});
	}	
	ans.push_back({n - 3, n - 1, 1, n});
	solve(n - 2);
}

int main() {
	int n;
	cin >> n;
	solve(n);
	cout << ans.size() << endl;
	for (auto vec : ans) {
		cout << vec.size() << " ";
		for (auto x : vec) {
			cout << x << " ";
		}
		cout << endl;
	}
}
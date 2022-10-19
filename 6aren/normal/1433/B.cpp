#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &e : a)
			cin >> e;
		while (a.back() == 0)
			a.pop_back();
		reverse(a.begin(), a.end());
		while (a.back() == 0)
			a.pop_back();

		int ans = 0;
		for (int e : a)
			ans += (e == 0);
		cout << ans << '\n';
	}


	return 0;
}
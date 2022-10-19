#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a + b > n - 2) {
		cout << -1 << '\n';
		return;
	}
	if (abs(a - b) > 1) {
		cout << -1 << '\n';
		return;
	}	

	vector<int> big;
	vector<int> small;
	vector<int> med;
	int cnt = 1;
	for (int i = 0; i < b; ++i)
		small.push_back(cnt++);
	for (int i = 0; i < n - a - b; ++i)
		med.push_back(cnt++);
	for (int i = 0; i < a; ++i)
		big.push_back(cnt++);

	vector<int> ans;

	int ia = 0;
	int ib = 0;
	int im = 0;

	if (a > b) {
		reverse(med.begin(), med.end());
	}

	ans.push_back(med[im++]);

	if (a == b) {
		for (int i = 0; i < b; ++i) {
			ans.push_back(big[ia++]);
			ans.push_back(small[ib++]);
		}
		while (im != med.size())
			ans.push_back(med[im++]);
	} else if (a > b) {
		ans.push_back(big[ia++]);
		for (int i = 0; i < b; ++i) {
			ans.push_back(small[ib++]);
			ans.push_back(big[ia++]);
		}
		while (ia != a) {
			if (im == med.size()) {
				cout << -1 << '\n';
				return;
			} else {
				ans.push_back(med[im++]);
			}


			if (im == med.size()) {
				cout << -1 << '\n';
				return;
			} else {
				ans.push_back(med[im++]);
			}

			ans.push_back(big[ia++]);
		}
		if (im == med.size()) {
			cout << -1 << '\n';
			return;
		} else {
			ans.push_back(med[im++]);
		}
		while (im != med.size())
			ans.push_back(med[im++]);
	} else {
		ans.push_back(small[ib++]);
		for (int i = 0; i < a; ++i) {
			ans.push_back(big[ia++]);
			ans.push_back(small[ib++]);
		}
		while (ib != b) {
			if (im == med.size()) {
				cout << -1 << '\n';
				return;
			} else {
				ans.push_back(med[im++]);
			}


			if (im == med.size()) {
				cout << -1 << '\n';
				return;
			} else {
				ans.push_back(med[im++]);
			}

			ans.push_back(small[ib++]);
		}
		if (im == med.size()) {
			cout << -1 << '\n';
			return;
		} else {
			ans.push_back(med[im++]);
		}
		while (im != med.size())
			ans.push_back(med[im++]);

	}

	for (int i : ans)
		cout << i << ' ';
	cout << '\n';

	// vector<int> v(n);
	// for (int i = 0; i < a; i++)
	// 	v[2 * i + 1] = n - i + 1;

	// for (int i = 0; i < b; i++)
	// 	v[2 * i + 2] = i + 1;

	// int cnt = b + 1;
	// for (int i = 0; i < n; ++i)
	// 	if (v[i] == 0)
	// 		v[i] = cnt++;

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    	solve();

	return 0;
}
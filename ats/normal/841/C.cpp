#include <bits/stdc++.h>
using namespace std;
#define int long long
struct T {
	int b;
	int ind;
	bool operator<(const T& right) const {
		return b > right.b;
	}
};
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> res(n);
	vector<T> t(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i].b;
		t[i].ind = i;
	}
	sort(a.begin(), a.end());
	sort(t.begin(), t.end());

	for (int i = 0; i < n; i++) {
		res[t[i].ind] = a[i];
	}
	for (int i = 0; i < n; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
	
	return 0;
}
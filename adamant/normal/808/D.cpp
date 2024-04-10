#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

bool check(vector<int> a) {
	int n = a.size();
	int p[n + 1];
	p[0] = 0;
	for(int i = 0; i < n; i++) {
		p[i + 1] = p[i] + a[i];
	}
	int s = p[n];
	set<int> nums;
	for(int i = 0; i <= n; i++) {
		int diff = p[i] - (s - p[i]);
		if(diff % 2 == 0 && nums.count(diff / 2)) {
			return 1;
			return 0;
		}
		if(i < n) {
			nums.insert(a[i]);
		}
	}
	return 0;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> A(a, a + n);
	vector<int> B(A.rbegin(), A.rend());
	cout << (check(A) || check(B) ? "YES" : "NO") << endl;
	return 0;
}
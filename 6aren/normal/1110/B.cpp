#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int n, m, k, a[100005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n >> m >> k;
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i] - a[i - 1]);
	}
	int res = a[n - 1] - a[0] + 1;
	int cnt = 1;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (cnt == k) break;
		res -= v[i] - 1;
		cnt++;
	}
	cout << res;
	return 0;
}
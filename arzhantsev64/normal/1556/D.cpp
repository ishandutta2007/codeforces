#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int get_sum(int i, int j) {
	cout << "or " << i + 1 << ' ' << j + 1 << endl;
	int x1;
	cin >> x1;
	cout << "and " << i + 1 << ' ' << j + 1 << endl;
	int x2;
	cin >> x2;
	return x1 + x2;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int s1 = get_sum(0, 1);
	int s2 = get_sum(1, 2);
	int s3 = get_sum(0, 2);
	vector<int> v(n);
	v[0] = (s1 - s2 + s3) / 2;
	v[1] = (s1 + s2 - s3) / 2;
	v[2] = (-s1 + s2 + s3) / 2;
	for (int i = 3; i < n; ++i) {
		v[i] = get_sum(0, i) - v[0];
	}
	sort(v.begin(), v.end());
	cout << "finish " << v[k - 1] << endl;

	return 0;
}
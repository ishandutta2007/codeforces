#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	for (string &s : a)
		cin >> s;

	auto f = [&](const int i, const int j) {
		return a[i][j] == 'X';
	};

	int cnt = 0;
	for (int i = 1; i + 1 < n; ++i)
		for (int j = 1; j + 1 < n; ++j)
			if (f(i, j) && f(i + 1, j + 1) && f(i - 1, j + 1) && f(i + 1, j - 1) && f(i - 1, j - 1))
				++cnt;
	cout << cnt;
	return 0;
}
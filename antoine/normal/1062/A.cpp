#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	a[0] = 0;
	a[n + 1] = 1001;

	int cnt = 0, res = 0;
	for (int i = 0; i <= n; ++i)
		if (a[i + 1] == a[i] + 1)
			res = max(res, ++cnt);
		else
			cnt = 0;
	cout << max(0, res - 1);
	return 0;
}
#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n, L, a;
	cin >> n >> L >> a;
	vector<int> t(n), l(n);
	for (int i = 0; i < n; ++i)
		cin >> t[i] >> l[i];

	int ans = 0;
	if (!n)
		ans = L / a;
	else {
		ans += t[0] / a;
		for (int i = 0; i + 1 < n; ++i)
			ans += (t[i + 1] - (t[i] + l[i])) / a;
		ans += (L - (t[n - 1] + l[n - 1])) / a;
	}
	cout << ans << '\n';
	return 0;
}
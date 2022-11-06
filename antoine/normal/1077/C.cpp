#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (auto &&x : a)
		cin >> x;

	const ll sum = accumulate(a.begin(), a.end(), 0LL);

	vector<int> b = a;
	nth_element(b.rbegin(), b.rend() - 2, b.rend());
	b.resize(2);
	sort(b.begin(), b.end());

	vector<int> res;
	for (int i = 0; i < n; ++i) {
		const int mx = a[i] == b.back() ? b[0] : b.back();
		if (mx * 2 == (sum - a[i]))
			res.push_back(i);
	}
	cout << res.size() << '\n';
	for (auto &&x : res)
		cout << x + 1 << ' ';
	return 0;
}
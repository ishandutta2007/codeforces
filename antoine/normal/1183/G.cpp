#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

vector<int> f(vector<int> a) {
	const int n = (int) a.size();
	assert(is_sorted(a.begin(), a.end()));
	for (int i = n - 2; i >= 0; --i)
		a[i] = min(a[i], a[i + 1] - 1);
	for (int &x : a)
		x = max(0, x);
	return a;
}
void f() {
	int n;
	cin >> n;
	vector<int> a(n, 0), b(n, 0);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		++a[x - 1];
		if (y)
			++b[x - 1];
	}

	{
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; ++i)
			v[i] = {a[i], b[i]};
		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			a[i] = v[i].first;
			b[i] = v[i].second;
		}
	}

	const vector<int> v = f(a);

	multiset<int> ms;
	int ans2 = 0;

	for (int i = n - 1, j = n - 1; i >= 0 && v[i]; --i) {
		while (j >= 0 && a[j] >= v[i])
			ms.insert(b[j--]);
		assert(!ms.empty());
		ans2 += min(v[i], *ms.rbegin());
		ms.erase(--ms.end());
	}

	const int ans1 = accumulate(v.begin(), v.end(), 0);

	cout << ans1 << ' ' << ans2 << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
		f();
	return 0;
}
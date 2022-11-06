#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> l(n), r(n);
	for(int i = 0; i < n; ++i)
		cin >> l[i] >> r[i];

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	ll res = n;
	for(int i = 0; i < n; ++i)
		res += max(l[i], r[i]);

	cout << res << '\n';
	return 0;
}
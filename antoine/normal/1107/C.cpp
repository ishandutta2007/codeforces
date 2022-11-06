#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int &x : a)
		cin >> x;
	string s;
	cin >> s;

	vector<vector<int>> v;
	for (int i = 0; i < n; ++i)
		if (i == 0 || s[i] != s[i - 1])
			v.push_back( { a[i] });
		else
			v.back().push_back(a[i]);

	ll res = 0;
	for (vector<int> &u : v) {
		sort(u.rbegin(), u.rend());
		if ((int)u.size() >= k)
			u.resize(k);
		res += accumulate(u.begin(), u.end(), 0LL);
	}
	cout << res;
	return 0;
}
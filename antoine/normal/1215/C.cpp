#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	vector<int> v1, v2;

	{
		string s, t;
		cin >> n >> s >> t;

		for (int i = 0; i < n; ++i)
			if (s[i] != t[i])
				(s[i] == 'a' ? v1 : v2).push_back(i + 1);
	}

	if ((v1.size() + v2.size()) & 1) {
		cout << -1;
		return 0;
	}
	cout << (v1.size() + 1) / 2 + (v2.size() + 1) / 2 << '\n';
	for (vector<int> * p : { &v1, &v2 }) {
		while ((int) p->size() > 1) {
			int i = p->back();
			p->pop_back();
			int j = p->back();
			p->pop_back();
			cout << i << ' ' << j << '\n';
		}
	}
	if (!v1.empty()) {
		cout << v1[0] << ' ' << v1[0] << '\n';
		cout << v1[0] << ' ' << v2[0] << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
	int n;
	string s;
	cin >> n >> s;
	for (char c = '0'; c <= '9'; ++c) {
		vector<int> v1, v2;
		for (int i = 0; i < n; ++i)
			if (s[i] < c)
				v1.push_back(i);
			else if (s[i] > c)
				v2.push_back(i);
		vector<int> v3;
		for (int i = 0; i < n; ++i)
			if (s[i] == c) {
				if (v1.empty() || i > v1.back())
					v1.push_back(i);
				else
					v3.push_back(i);
			}
		if (!v2.empty() && !v3.empty() && v3.back() > v2.front())
			continue;
		v2.insert(v2.begin(), v3.begin(), v3.end());
		bool ok = true;
		for (int i = 0; i + 1 < (int) v1.size(); ++i)
			ok &= s[v1[i]] <= s[v1[i + 1]];
		for (int i = 0; i + 1 < (int) v2.size(); ++i)
			ok &= s[v2[i]] <= s[v2[i + 1]];
		if (ok) {
			for (int i : v1)
				s[i] = '1';
			cout << '\n';
			for (int i : v2)
				s[i] = '2';
			cout << s << '\n';
			return;
		}
	}
	cout << "-\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		f();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, a[2];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;

	vector<string> v = { string(n, '0') + string(n, '1') + string(n, '2') };

	{
		string s;
		for (int i = 0; i < n; ++i)
			s += "012";
		v.push_back(s);
	}

	for (const string s : v) {
		string mp = "abc";
		do {
			string t;
			for (char c : s) {
				t += mp[c - '0'];
			}
			for (int i = 0;; ++i) {
				if (i == (int) t.size() - 1) {
					cout << "YES\n" << t;
					return 0;
				}
				const string tt = t.substr(i, 2);
				if (tt == s1 || tt == s2)
					break;

			}
		} while (next_permutation(mp.begin(), mp.end()));
	}

	return 0;
}
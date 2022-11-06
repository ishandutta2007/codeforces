#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, a[2];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> p(n), q(n);
	for (int &x : p) {
		cin >> x;
		--x;
	}
	for (int &x : q) {
		cin >> x;
		--x;
	}

	string res(n, '.');
	char c = 'a';
	for (int i = 0; i < n; c = min('z', char(c + 1)), --k) {
		map<int, int> mp;
		do {
			if (i >= n)
				return 0;
			// assert(i < n);
			if (!++mp[p[i]])
				mp.erase(p[i]);
			if (!--mp[q[i]])
				mp.erase(q[i]);
			res[q[i]] = c;
			++i;
		} while (mp.size());
	}
	if (k > 0)
		cout << "NO";
	else
		cout << "YES\n" << res;

	return 0;
}
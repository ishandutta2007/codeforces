#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s, res;
	cin >> s;
	for (int i = 0, j = (int) s.size() - 1;; ++i, --j) {
		if (j - i <= 2) {
			string temp = res;
			reverse(temp.begin(), temp.end());
			if (i <= j)
				res += s[i];
			res += temp;
			break;
		}
		for (int di = 0; di < 2; ++di)
			for (int dj = 0; dj < 2; ++dj)
				if (s[i + di] == s[j - dj]) {
					i += di;
					j -= dj;
					res += s[i];
					di = 2;
					break;
				}
	}
	cout << res;
	return 0;
}
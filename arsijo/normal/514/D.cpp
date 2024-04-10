/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
const int mod = 1000000007;

int n, m, k, ar[100000][5];
vector<int> ve;
multiset<int> s[5];

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];

	int ans = -1;

	for (int l = 0, r = 0; r < n; r++) {
		for (int i = 0; i < m; i++)
			s[i].insert(ar[r][i]);
		while (l <= r) {

			int a = 0;
			for (int i = 0; i < m; i++)
				a += *s[i].rbegin();

			if (a <= k)
				break;

			for (int j = 0; j < m; j++)
				s[j].erase(s[j].find(ar[l][j]));

			l++;

		}

		if (r - l > ans) {
			ve.clear();
			for (int i = 0; i < m; i++)
				ve.push_back(*s[i].rbegin());
			ans = r - l;
		}

	}

	if (ve.size() == 0)
		for (int i = 0; i < m; i++)
			cout << "0 ";
	else
		for (int i = 0; i < m; i++)
			cout << ve[i] << " ";

}
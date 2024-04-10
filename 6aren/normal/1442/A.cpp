#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(s) (s).begin(), (s).end()
#define bit(x, y) ((x >> y) & 1)

const int N = 30005;

int n, a[N];


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;
	while (ntest--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		int cura = a[1];
		int curb = 0;

		bool ok = 1;

		for (int i = 2; i <= n; i++) {
			int tmpa = min({a[i], cura, a[i] - curb});
			int tmpb = a[i] - tmpa;

			if (tmpa < 0 || tmpb < 0)
				ok = 0;
			cura = tmpa;
			curb = tmpb;
		}

		cout << (ok ? "YES\n" : "NO\n");

	}

	return 0;
}
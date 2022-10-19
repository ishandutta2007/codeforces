#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(s) (s).begin(), (s).end()
#define bit(x, y) ((x >> y) & 1)


const int N = 200005;
const int MOD = 998244353;

int n, k;
int a[N], b[N];
int l[N], r[N];


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;

	cin >> ntest;

	while (ntest--) {
		cin >> n >> k;


		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= k; i++)
			cin >> b[i];

		for (int i = 0; i <= n; i++) {
			l[a[i]] = a[i + 1];
		}
		for (int i = 1; i <= n + 1; i++) {
			r[a[i]] = a[i - 1];
		}

		vector<bool> check(n + 5);

		for (int i = 1; i <= k; i++) {
			check[b[i]] = 1;
		}
		check[0] = 1;

		int ans = 1;

		for (int i = 1; i <= k; i++) {
			int u = b[i];
			int le = l[u];
			int ri = r[u];

			if (check[le] && check[ri])
				ans = 0;

			if (check[le]) {
				r[u] = r[ri];
				l[r[u]] = u;
			}
			if (check[ri]) {
				l[u] = l[le];
				r[l[u]] = u;
			}

			if (!check[le] && !check[ri])
				ans = ans * 2 % MOD;

			check[u] = 0;
		}

		cout << ans << '\n';

		for (int i = 0; i <= n; i++) {
			a[i] = b[i] = 0;
			l[i] = r[i] = 0;
		}

	}

	return 0;
}
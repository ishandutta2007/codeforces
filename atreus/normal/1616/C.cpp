#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 1e5 + 1;

int a[100];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int answer = n - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// long double d = (a[j] - a[i]) / (j - i);
			int cnt = 0;
			int x = a[j] - a[i];
			for (int k = 1; k <= n; k++) {
				int t = (i - k) * (a[j] - a[i]);
				if (t % (j - i) != 0 || a[k] + (t / (j - i)) != a[i])
					cnt++;
			}
			answer = min(answer, cnt);
		}
	}
	cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}
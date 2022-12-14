#include <bits/stdc++.h>
#define bit(n, k) ((n >> k) & 1)
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 10;

int a[maxn], cnt[maxn];
vector<int> v[maxn];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n + 1; i++)
		cnt[i] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int bestx = -1, besty = -1;
	int tot = 0;
	int y = 0;
	for (int x = 1; x <= n; x++) {
		tot -= cnt[x - 1];
		while (y <= n and tot - (n - tot) < k) {
			y++;
			tot += cnt[y];
		}
		if (y == n + 1)
			break;
		if (bestx == -1 || (besty - bestx > y - x)) {
			bestx = x;
			besty = y;
		}
	}
	cout << bestx << " " << besty << '\n';
	int x = bestx;
		y = besty;
	int l = 1, now = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= x and a[i] <= y)
			now++;
		else
			now--;
		if ((now > 0 and k > 1) or i == n) {
			now = 0;
			cout << l << " " << i << '\n';
			l = i + 1;
			k--;
			continue;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}
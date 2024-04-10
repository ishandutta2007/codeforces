#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 2009;
pair<int, int> rows[MxN + 9];
pair<int, int> cols[MxN + 9];
int dp1[MxN + 9][MxN + 9];
int dp2[MxN + 9][MxN + 9];

int cnt;

void f(pair<int, int> &p, const int x) {
	if (p.first == -1) {
		--cnt;
		p.first = p.second = x;
	} else {
		p.first = min(p.first, x);
		p.second = max(p.second, x);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	memset(rows, -1, sizeof rows);
	memset(cols, -1, sizeof cols);

	int n, k;
	cin >> n >> k;

	cnt = 2 * n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			{
				char c;
				cin >> c;
				if (c == 'W')
					continue;
				assert(c == 'B');
			}
			f(rows[i], j);
			f(cols[j], i);
		}
	assert(cnt >= 0);

	for (int i = 0; i + k <= n; ++i) {
		int temp = 0;
		for (int j = 0; j < n; ++j) {
			temp += cols[j].first != -1 && i <= cols[j].first && cols[j].second < i + k;
			if (j - k >= 0)
				temp -= cols[j - k].first != -1 && i <= cols[j - k].first && cols[j - k].second < i + k;
			if (j - k + 1 >= 0)
				dp1[i][j - k + 1] = temp;
		}
	}

	for (int j = 0; j + k <= n; ++j) {
		int temp = 0;
		for (int i = 0; i < n; ++i) {
			temp += rows[i].first != -1 && j <= rows[i].first && rows[i].second < j + k;
			if (i - k >= 0)
				temp -= rows[i - k].first != -1 && j <= rows[i - k].first && rows[i - k].second < j + k;
			if (i - k + 1 >= 0)
				dp2[i - k + 1][j] = temp;
		}
	}

	DBG(cnt)
	DBG(dp1[2][1])
	DBG(dp2[2][1])
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ans = max(ans, cnt + dp1[i][j] + dp2[i][j]);

		}
	assert(ans >= cnt);
	cout << ans;
	return 0;
}
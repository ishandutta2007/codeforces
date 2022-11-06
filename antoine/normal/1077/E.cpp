#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 2e5 + 9;

int n;
int cnts[MaxN + 9];

int f(int x) {
	int res = 0;
	for (int i = 0;; x <<= 1) {
		i = lower_bound(cnts + i, cnts + n, x) - cnts;
		if (i++ == n)
			break;
		res += x;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	{
		cin >> n;
		map<int, int> occ;
		while (n--) {
			int x;
			cin >> x;
			++occ[x];
		}
		assert(++n == 0);
		for (auto &&x : occ)
			cnts[n++] = x.second;
	}

	sort(cnts, cnts + n);

	int ans = 0;
	for (int start = MaxN; start > 0; --start)
		ans = max(ans, f(start));
	cout << ans;
	return 0;
}
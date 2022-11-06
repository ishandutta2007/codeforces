#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = (int) 2e5 + 99;
int cnt[Mx + 99];
int cs[Mx + 99];
int cs2[Mx + 99];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	{
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			if (++cnt[x] == 2)
				cs2[x] = 1;
		}
	}

	partial_sum(begin(cnt), end(cnt), cs);
	partial_sum(begin(cs2), end(cs2), cs2);

	int ans = -1;
	pair<int, int> choice;

	for (int i = 0; i < Mx; ++i)
		if (cnt[i]) {
			int lo = i;
			int hi = Mx;
			while (lo < hi) {
				const int mid = (lo + hi + 1) / 2;
				if (cs2[mid] - cs2[i] == mid - i)
					lo = mid;
				else
					hi = mid - 1;
			}
			if (cnt[lo + 1])
				lo++;

			const int cand = cs[lo] - (i ? cs[i - 1] : 0);
			if (cand > ans) {
				ans = cand;
				choice = {i, lo};
			}
		}
	cout << ans << endl;
	for (int i = choice.first; i <= choice.second; ++i)
		cout << i << ' ';
	for (int i = choice.second; i >= choice.first; --i)
		for (int rep = 0; rep < cnt[i] - 1; ++rep)
			cout << i << ' ';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int a[1010], n, orig[1010];
vector<int> swaps[1010];
vector<pair<int, int> > ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) swaps[j].push_back(i);
		}
		orig[i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		vector<pair<int, int> > doing;
		for (auto j : swaps[i]) {
			doing.emplace_back(orig[j], j);
		}
		sort(doing.begin(), doing.end());
		reverse(doing.begin(), doing.end());
		int have = a[i];
		for (auto j : doing) {
			swap(have, a[j.second]);
			ans.emplace_back(i, j.second);
		}
		a[i] = have;
	}
	D("%d\n", n);
	for (int i = 0; i < n; i++) D("%d ", orig[i]);
	D("\n");
	printf("%lu\n", ans.size());
	for (auto i : ans) printf("%d %d\n", i.first+1, i.second+1);
}
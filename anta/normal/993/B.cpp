#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		array<vector<pair<int, int>>, 2> pairs;
		for (int k = 0; k < 2; ++ k) {
			for (int i = 0; i < (k == 0 ? n : m); ++ i) {
				int x; int y;
				scanf("%d%d", &x, &y);
				if (x > y) swap(x, y);
				if (x == y) continue;
				pairs[k].emplace_back(x, y);
			}
		}
		set<int> cands;
		array<map<pair<int, int>, set<int>>, 2> sets;
		for (auto p : pairs[0]) for(auto q : pairs[1]) {
			map<int, int> cnt;
			for (int x : {p.first, p.second, q.first, q.second })
				++ cnt[x];
			if (cnt.size() != 3) continue;
			int x = -1;
			for (auto c : cnt) if (c.second == 2)
				x = c.first;
			cands.insert(x);
			sets[0][p].insert(x);
			sets[1][q].insert(x);
		}
		bool ok = true;
		for (int k = 0; k < 2; ++ k) for (auto p : sets[k])
			ok &= p.second.size() == 1;
		if (cands.size() == 1)
			printf("%d\n", *cands.begin());
		else if (ok)
			puts("0");
		else
			puts("-1");
	}
}
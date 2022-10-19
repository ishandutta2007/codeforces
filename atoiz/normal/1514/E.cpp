#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <numeric>
#include <cstdio>

using namespace std;

int main() {
	int tests;
	scanf("%d", &tests);
	while (tests--) {
		int n;
		scanf("%d", &n);

		const auto dir = [&](int u, int v) -> bool {
			printf("1 %d %d\n", u, v);
			fflush(stdout);
			int d;
			scanf("%d", &d);
			return d;
		};

		vector<int> path = {0};
		for (int i = 1; i < n; ++i) {
			if (dir(i, path.front())) {
				path.insert(path.begin(), i);
			} else if (dir(path.back(), i)) {
				path.push_back(i);
			} else {
				int lo = 0, hi = (int) path.size() - 1;
				while (lo + 1 < hi) {
					int md = (lo + hi) >> 1;
					if (dir(path[md], i)) lo = md;
					else hi = md;
				}
				path.insert(path.begin() + hi, i);
			}
		}

		const auto dominated = [&](int i, int r) -> bool {
			printf("2 %d %d", path[i], r);
			for (int j = 0; j < r; ++j) printf(" %d", path[j]);
			puts("");
			fflush(stdout);
			int d;
			scanf("%d", &d);
			return !d;
		};

		vector<int> split = {n};
		for (int i = n - 1, r = n - 1; i > 0; --i) {
			for (r = min(r, i); r > 0 && !dominated(i, r); --r);
			if (r == i) split.push_back(i);
		}

		vector<string> ans(n, string(n, '1'));
		for (int k = 1; k < (int) split.size(); ++k) {
			for (int i = split[k - 1] - 1; i >= split[k]; --i) {
				for (int j = split[k] - 1; j >= 0; --j) {
					ans[path[i]][path[j]] = '0';
				}
			}
		}

		puts("3");
		for (string s : ans) puts(s.c_str());
		fflush(stdout);
		int v;
		scanf("%d", &v);
		assert(v == 1);
	}
}
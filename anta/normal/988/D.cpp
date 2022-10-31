#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		map<int, int> cnt;
		for (int i = 0; i < n; ++ i) {
			int x;
			scanf("%d", &x);
			++ cnt[x];
		}
		int ans = 0;
		vector<int> coords;
		auto update = [&](vector<int> xs) {
			int num = 0;
			for (int x : xs) {
				auto it = cnt.find(x);
				num += it != cnt.end() ? it->second : 0;
			}
			if (ans < num) {
				ans = num;
				coords = xs;
			}
		};
		for (auto p : cnt) {
			int x = p.first;
			update({ x });
			for (int k = 0; x + (1LL << k) <= (int)1e9; ++ k) {
				update({ x, x + (1 << k) });
				if (0 < k) update({ x, x + (1 << (k - 1)), x + (1 << k) });
			}
		}
		printf("%d\n", ans);
		vector<int> v;
		for (int x : coords) {
			int n = cnt[x];
			for (int j = 0; j < n; ++ j)
				v.push_back(x);
		}
		for (int i = 0; i < (int)v.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", v[i]);
		}
		puts("");
	}
}
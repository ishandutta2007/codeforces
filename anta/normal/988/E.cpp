#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

int main() {
	const int INF = 0x3f3f3f3f;
	long long n;
	while (~scanf("%lld", &n)) {
		if (n < 10) {
			puts("-1");
			continue;
		}
		vector<int> digits;
		for (auto x = n; x > 0; x /= 10)
			digits.push_back(x % 10);
		int ans = INF;
		for (int lo = 0; lo < 100; lo += 25) for (int ord = 0; ord < 2; ++ ord) {
			vector<int> v = digits;
			int cost = 0;
			auto mov = [&](int i, int j) {
				if (i < j) {
					for (; i < j; ++ i)
						swap(v[i], v[i + 1]), ++ cost;
				} else if (i > j) {
					for (; i > j; -- i)
						swap(v[i], v[i - 1]), ++ cost;
				}
			};
			for (int k = 0; k < 2; ++ k) {
				int d = (k ^ ord) == 0 ? lo % 10 : lo / 10;
				int target = ord == 0 ? k : 0;
				for (int i = k; i != v.size(); ++ i) if (v[i] == d) {
					mov(i, target);
					for (int j = (int)v.size() - 1; j > 0; -- j) {
						if (v[j] != 0) {
							mov(j, (int)v.size() - 1);
							break;
						}
					}
					break;
				}
			}

			if (v[0] + v[1] * 10 == lo)
				amin(ans, cost);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
}
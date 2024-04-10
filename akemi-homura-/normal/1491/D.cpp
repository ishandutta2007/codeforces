#include <bits/stdc++.h>
using namespace std;
#define pc __builtin_popcountll
inline bool gao(long long x, long long y) {
	for (int i = 40; i >= 0; i--) if ((x >> i & 1) != (y >> i & 1)) {
		if (x > y) return false;
		if (pc(x) < pc(y)) return false;
		x ^= (1ll << i);
		for (int j = i - 1; j >= 0 && pc(x) > pc(y); j--) {
			if (x >> j & 1) x ^= (1ll << j);
		}
		assert(pc(x) == pc(y));
		vector<int> v1, v2;
		for (int j = i; j >= 0; j--) if (x >> j & 1) v1.push_back(j);
		for (int j = i; j >= 0; j--) if (y >> j & 1) v2.push_back(j);
		for (int j = 0; j < (int)v1.size(); j++) {
			if (v1[j] > v2[j]) return false;
		}
		return true;
	} else if ((x >> i & 1)) {
		x ^= (1ll << i);
		y ^= (1ll << i);
	}
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		puts(gao(x, y) ? "YES" : "NO");
	}
	return 0;
}
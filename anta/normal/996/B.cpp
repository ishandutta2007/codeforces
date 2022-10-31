#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		const int INF = 0x3f3f3f3f;
		pair<int, int> ans(INF, -1);
		for (int i = 0; i < n; ++ i) {
			amin(ans, make_pair((a[i] + (n - 1 - i)) / n * n + i, i));
		}
		printf("%d\n", ans.second + 1);
	}
}
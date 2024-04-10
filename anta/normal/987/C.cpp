#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> s(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &s[i]);
		vector<int> c(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &c[i]);
		const int INF = 0x3f3f3f3f;
		int ans = INF;
		for (int j = 1; j < n - 1; ++ j) {
			int L = INF, R = INF;
			for (int i = 0; i < j; ++ i) if (s[i] < s[j])
				amin(L, c[i]);
			for (int k = j + 1; k < n; ++ k) if (s[j] < s[k])
				amin(R, c[k]);
			if (L < INF && R < INF)
				amin(ans, L + c[j] + R);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
}
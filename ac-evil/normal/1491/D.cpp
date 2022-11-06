#include <bits/stdc++.h>
using std::min; using std::max;
typedef long long LL;
//const int N = ;
int Q;
int main() {
	scanf("%d", &Q);
	while (Q--) {
		int u, v; scanf("%d%d", &u, &v);
		if (u > v) puts("NO");
		else {
			int tot1 = 0, tot2 = 0, ok = 1;
			for (int i = 0; i < 30; i++) {
				tot1 += u & 1, tot2 += v & 1;
				if (tot1 < tot2) { ok = 0; break; }
				u >>= 1, v >>= 1;
			}
			if (ok) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
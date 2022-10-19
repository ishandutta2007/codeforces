#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		int am = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			if (a) {
				am++;
			} else {
				if (am) ans++;
				am = 0;
			}
		}
		if (am) ans++;
		ans = min(2, ans);
		printf("%d\n", ans);
	}
}
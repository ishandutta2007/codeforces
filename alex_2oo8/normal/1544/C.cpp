#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

int a[MX], b[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
		for (int i = 0; i < n; i++) ignore = scanf("%d", b + i);
		
		sort(a, a + n);
		sort(b, b + n);
		
		reverse(a, a + n);
		reverse(b, b + n);
		
		auto ok = [n](int k) {
			int cnt = (n + k) - (n + k) / 4;
			
			int add = min(cnt, k);
			int aa = add * 100 + accumulate(a, a + (cnt - add), 0);
			
			int bb = accumulate(b, b + min(cnt, n), 0);
			
			return aa >= bb;
		};
		
		int k = -1;
		for (int p = (1 << 20); p > 0; p /= 2) {
			if (ok(k + p) == false) k += p;
		}
		
		k++;
		
		int ans = k;
		for (int x = 0; x < 42 && x <= k; x++) {
			if (ok(k - x)) ans = k - x;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
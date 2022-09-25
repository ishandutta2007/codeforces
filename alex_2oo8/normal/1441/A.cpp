#include <bits/stdc++.h>

using namespace std;

const int MX = 200000, md = 998244353;

int a[MX], b[MX], p[MX];
bool done[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, k;
		ignore = scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			ignore = scanf("%d", a + i);
			a[i]--;
		}
		
		for (int i = 0; i < k; i++) {
			ignore = scanf("%d", b + i);
			b[i]--;
		}
		
		fill(done, done + n, true);
		for (int i = 0; i < k; i++) done[b[i]] = false;
		
		set<int> alive;
		for (int i = 0; i < n; i++) {
			p[a[i]] = i;
			alive.insert(i);
		}
		
		int ans = 1;
		for (int i = 0; i < k; i++) {
			auto it = alive.find(p[b[i]]);
			assert(it != alive.end());
			
			int L = -1, R = -1;
			if (it != alive.begin()) {
				L = *prev(it);
			}
			
			if (next(it) != alive.end()) {
				R = *next(it);
			}
			
			int x;
			if (L != -1 && R != -1 && done[a[L]] && done[a[R]]) {
				ans = 2 * ans % md;
				x = L;
			}
			else if (L != -1 && done[a[L]]) {
				x = L;
			}
			else if (R != -1 && done[a[R]]) {
				x = R;
			}
			else {
				ans = 0;
				break;
			}
			
			alive.erase(x);
			
			done[b[i]] = true;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
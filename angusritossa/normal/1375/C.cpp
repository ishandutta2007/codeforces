#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int n, a[300010], mx[300010], at[300010];
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			at[a[i]] = i;
			mx[i] = -1;
		}
		for (int i = 2; i <= n; i++) {
			at[i] = min(at[i], at[i-1]);
		}
		
		for (int i = 0; i < n; i++) {
			mx[at[a[i]]] = i;
		}
		stack<int> s;
		for (int i = 0; i < n; i++) {
			if (s.size() && a[i] > a[s.top()]) {
				if (mx[s.top()] < i) {
					s.pop();
					i--;
					continue;
				}
			} else {
				s.push(i);
			}
		}
		if (s.size() == 1) printf("YES\n");
		else printf("NO\n");
	}
}
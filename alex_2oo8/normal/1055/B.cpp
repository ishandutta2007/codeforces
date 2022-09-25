#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

long long a[MX + 2];

int main() {
	int n, m, l;
	ignore = scanf("%d %d %d", &n, &m, &l);
	for (int i = 1; i <= n; i++) ignore = scanf("%lld", a + i);
	
	int f = 0;
	for (int i = 1; i <= n + 1; i++) if ((a[i - 1] > l) != (a[i] > l)) f++;
	
	while (m--) {
		int x;
		ignore = scanf("%d", &x);
		if (x == 0) printf("%d\n", f / 2);
		else {
			int p, d;
			ignore = scanf("%d %d", &p, &d);
			
			if ((a[p - 1] > l) != (a[p] > l)) f--;
			if ((a[p + 1] > l) != (a[p] > l)) f--;
			
			a[p] += d;
			
			if ((a[p - 1] > l) != (a[p] > l)) f++;
			if ((a[p + 1] > l) != (a[p] > l)) f++;
		}
	}
	
	return 0;
}
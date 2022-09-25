#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX];

void yes(int n) {
	printf("YES\n");
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	exit(0);
}

void no() {
	printf("%s\n", "NO");
	exit(0);
}

vector<int> f[MX];

int main() {
	int n, q, z = -1;
	ignore = scanf("%d %d", &n, &q);
	for (int i = 0, p = 0; i < n; i++) {
		ignore = scanf("%d", a + i);
		if (a[i] == 0) {
			a[i] = p;
			z = i;
		}
		p = a[i];
	}
	
	if (count(a, a + n, q) == 0) {
		if (z == -1) no();
		a[z] = q;
	}
	
	for (int i = n - 1, p = 0; i >= 0; i--) {
		if (a[i] == 0) a[i] = p;
		p = a[i];
	}
	
	for (int i = 0; i < n; i++) f[a[i] - 1].push_back(i);
	
	set<int> used;
	for (int i = 0; i < q; i++) {
		int l = n, r = -1;
		for (int x : f[i]) {
			l = min(l, x);
			r = max(r, x);
		}
		
		auto it = used.lower_bound(l);
		if (it != used.end() && *it < r) no();
		
		for (int x : f[i]) used.insert(x);
	}

	yes(n);
	
	return 0;
}
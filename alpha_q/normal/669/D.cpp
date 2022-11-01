#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 5;

int n, q, ev = 0, od = 0, first = 1;
int op[MAX], ara[MAX]; bool f = false;

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &n, &q);
	int id = 0, slide = 0; 
	for (int i = 1; i <= q; i++) {
		int a, b; scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			slide += b;
			slide += n;
			slide %= n;
			if (i == q) op[++id] = slide;
		} else {
			op[++id] = slide;
			slide = 0;
			if (i == q) f = true;
		}
	}
	
	for (int i = 1; i <= id; i++) {
		slide = op[i];
		ev += slide, od += slide;
		ev %= n, od %= n;
		first += slide; first %= 2;
		if (i == id and !f) continue;
		if (first == 1) od++, ev--, od %= n, ev %= n, first = 0;
		else od--, ev++, od %= n, ev %= n, first = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			int pos = (i + od) % n;
			if (pos == 0) pos = n;
			ara[pos] = i;
		} else {
			int pos = (i + ev) % n;
			if (pos == 0) pos = n;
			ara[pos] = i;
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", ara[i]);
	printf("\n");
	return 0;
}
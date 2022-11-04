#include <bits/stdc++.h>
#define M 500010

using namespace std;

int n, k, m, t;

int main() {
	scanf("%d%d%d%d", &n, &k, &m, &t);
	for(int i = 1; i <= t; i++) {
		int op, x;
		scanf("%d%d", &op, &x);
		if(op == 1) {
			if(x <= k) k++;
			n++;
		} else {
			if(k <= x) n = x; else n -= x, k -= x;
		}
		printf("%d %d\n", n, k);
	}
	return 0;
}
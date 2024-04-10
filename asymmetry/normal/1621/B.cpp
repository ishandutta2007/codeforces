//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

void solve() {
	int n, cl = 1e9, cr = 1e9, l = 1e9, r = 0, rr = 0, cost = 2e9;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (b - a + 1 > rr) {
			rr = b - a + 1;
			cost = c;
		}
		else if (b - a + 1 == rr) {
			cost = min(cost, c);
		}
		if (a < l) {
			l = a;
			cl = c;
		}
		else if (a == l) {
			cl = min(cl, c);
		}
		if (b > r) {
			r = b;
			cr = c;
		}
		else if (b == r) {
			cr = min(cr, c);
		}
		if (r - l + 1 > rr) {
			printf("%d\n", cl + cr);
		}
		else {
			printf("%d\n", min(cl + cr, cost));
		}
	}
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}
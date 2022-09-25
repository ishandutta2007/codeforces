#include <bits/stdc++.h>

using namespace std;

int solve_slow(int la, int ra, int ta, int lb, int rb, int tb) {
	int mn = tb;
	for (int x = 0; x < tb; x++) {
		mn = min(((la - lb + tb) + x * 1ll * ta) % tb, (long long)mn);
	}
	
	return rb - lb + 1 - mn;
}

int foo(int c, int ta, int tb) {
	ta %= tb;
	if (ta == 0) return c;
	int x = (tb - c + ta - 1) / ta;
	int r = (c + x * ta) % tb;
	return min(foo(r, tb % ta, ta), r);
}

int solve(int la, int ra, int ta, int lb, int rb, int tb) {
	int mn = foo((la - lb + tb) % tb, ta, tb);
	
	return rb - lb + 1 - mn;
}

int main() {
	/*
	for (int ta = 2; true; ta++) {
	for (int la = 0; la < ta; la++)
	for (int ra = la; ra < ta; ra++)
	for (int tb = 2; tb <= ta; tb++)
	for (int lb = 0; lb < tb; lb++)
	for (int rb = lb; rb < tb; rb++) {
		int f = solve(la, ra, ta, lb, rb, tb);
		int g = solve_slow(la, ra, ta, lb, rb, tb);
		
		if (f != g) printf("FAIL: %d %d %d %d %d %d\n", la, ra, ta, lb, rb, tb);
	}
	
		printf("ta = %d done\n", ta);
	}
	*/
	
	int la, ra, ta;
	int lb, rb, tb;
	ignore = scanf("%d %d %d", &la, &ra, &ta);
	ignore = scanf("%d %d %d", &lb, &rb, &tb);
	
	int f = solve(la, ra, ta, lb, rb, tb);
	int g = solve(lb, rb, tb, la, ra, ta);
	
	int h = min(ra - la + 1, rb - lb + 1);
	
	printf("%d\n", max(min(max(f, g), h), 0));
	
	return 0;
}
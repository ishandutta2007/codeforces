#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int a, b;
		ignore = scanf("%d %d", &a, &b);
		
		int x = (a + b + 1) / 2;
		int y = a + b - x;
		
		set<int> res;
		for (int it = 0; it < 2; it++) {
			for (int f = 0; f <= a && f <= x; f++) {
				if (a - f <= y) {
					res.insert(a - f + x - f);
				}
			}
			
			swap(x, y);
		}
		
		printf("%zu\n", res.size());
		for (int k : res) printf("%d ", k);
		printf("\n");
	}
	
	return 0;
}
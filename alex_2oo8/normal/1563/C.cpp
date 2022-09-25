#include <bits/stdc++.h>

using namespace std;

const int MX = 2021;

int a[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
		
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == i % 2) ok = false;
		}
		
		if (ok == false) {
			printf("%d\n", -1);
			continue;
		}
		
		vector<int> res;
		
		auto rev = [&](int p) {
			res.push_back(p);
			reverse(a, a + p);
		};
		
		while (n > 3) {
			rev((find(a, a + n, n) - a) + 1);
			rev(find(a, a + n, n - 1) - a);
			rev((find(a, a + n, n - 1) - a) + 2);
			rev(3);
			rev(n);
			
			n -= 2;
		}
		
		if (a[0] != 1) rev(3);
		
		printf("%zu\n", res.size());
		for (int p : res) printf("%d ", p);
		printf("\n");
	}
	
	return 0;
}
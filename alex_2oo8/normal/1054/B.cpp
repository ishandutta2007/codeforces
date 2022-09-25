#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, mex = 0;
	ignore = scanf("%d", &n);
	set<int> S;
	for (int i = 1, x; i <= n; i++) {
		ignore = scanf("%d", &x);
		if (x > mex) {
			printf("%d\n", i);
			return 0;
		}
		S.insert(x);
		while (S.count(mex) == 1) mex++;
	}
	
	printf("%d\n", -1);
	
	return 0;
}
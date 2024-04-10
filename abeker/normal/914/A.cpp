#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
	if (x < 0)
		return false;
	int tmp = sqrt((double)x);
	return tmp * tmp == x;
}

int main() {
	int N;
	scanf("%d", &N);
	int sol = -1e6;
	while (N--) {
		int x;
		scanf("%d", &x);
		if (!check(x))
			sol = max(sol, x);
	}
	printf("%d\n", sol);
	return 0;
}
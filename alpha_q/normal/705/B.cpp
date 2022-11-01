#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	int n, x, sum;
	scanf("%d", &n); while (n--) {
		scanf("%d", &x);
		sum += (x - 1);
		sum &= 1;
		printf("%d\n", 2 - sum);
	}
	return 0;
}
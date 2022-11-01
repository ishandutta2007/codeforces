#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	if (n & 1) {
		int k = 1 + (n - 3)/2;
		printf("%d\n3 ", k);
		--k;
		while (k--) {
			printf("2 ");
		}
		puts("");
	} else {
		int k = n/2;
		printf("%d\n", k);
		while (k--) {
			printf("2 ");
		}
		puts("");
	}
    return 0;
}
#include <bits/stdc++.h> 

using namespace std;

int n, sum = 0, big = 0;

int main (int argc, char const *argv[]) {
	scanf("%d", &n); 
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		sum += x, big = max(big, x);
	}
	printf("%d\n", n * big - sum);
	return 0;
}
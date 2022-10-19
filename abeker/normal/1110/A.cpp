#include <bits/stdc++.h>
using namespace std;

int main() {
	int B, K;
	int sum = 0, lst = 0;
	scanf("%d%d", &B, &K);
	while (K--) {
		int x;
		scanf("%d", &x);
		sum += x;
		lst = x;
	}
	
	int ans = B % 2 ? sum : lst;
	puts(ans % 2 ? "odd" : "even");
	
	return 0;
}
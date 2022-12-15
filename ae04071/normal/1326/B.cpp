#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x = 0,b;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&b);
		printf("%d ", b + x);
		x = max(x, b + x);
	}

	return 0;
}
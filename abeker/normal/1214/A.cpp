#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, D, E;
	scanf("%d%d%d", &N, &D, &E);
	
	E *= 5;
	
	int ans = N;
	for (int i = 0; i < 100000; i++) 
		if (i * D <= N)
			ans = min(ans, (N - i * D) % E);
	
	printf("%d\n", ans);
	
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	
	int ans = 2 * (d1 + d2);
	ans = min(ans, d1 + d2 + d3);
	ans = min(ans, 2 * (d1 + d3));
	ans = min(ans, 2 * (d2 + d3));
	
	printf("%d\n", ans);
	
	return 0;
}
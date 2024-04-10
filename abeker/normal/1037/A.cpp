#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	int ans = 0;
	while (1 << ans <= N)
		ans++;
	
	printf("%d\n", ans);
	
	return 0;
}
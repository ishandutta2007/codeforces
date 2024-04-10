#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int curr = 0, ans = 0, prev = 1e9;
	while (N--) {
		int x;
		scanf("%d", &x);
		if (x > 2 * prev) 
			curr = 0;
		ans = max(ans, ++curr);
		prev = x;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
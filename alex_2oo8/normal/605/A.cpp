#include<bits/stdc++.h>

using namespace std;

const int MX = 100000;

int p[MX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		p[a - 1] = i;
	}
	
	int ans = 1, cur = 1;
	for (int i = 1; i < n; i++) {
		if (p[i] > p[i - 1]) cur++;
		else cur = 1;
		
		ans = max(ans, cur);
	}
	
	printf("%d\n", n - ans);
	
	return 0;
}
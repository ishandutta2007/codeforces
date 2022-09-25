#include<bits/stdc++.h>

using namespace std;

int a[1000001];

int main() {
	int n, ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		if (++a[x] > a[ans]) ans = x;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
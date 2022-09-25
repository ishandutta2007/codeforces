#include<bits/stdc++.h>

using namespace std;

int a[1000];

int main() {
	int n, ans = 6;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		
		for (int j = 0; j < i; j++) {
			int k = -1, x = a[i], y = a[j];
			while (x != y) {
				if (x % 10 != y % 10) k++;
				
				x /= 10;
				y /= 10;
			}
			
			ans = min(k / 2, ans);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
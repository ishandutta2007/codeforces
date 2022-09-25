#include<bits/stdc++.h>

using namespace std;

const int MX = 1001;

int a[MX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		a[x] = 1;
	}
	
	for (int i = 0; i + 2 < 1001; i++)
		if (a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0) {
			printf("YES\n");
			
			return 0;
		}
	
	printf("NO\n");
	
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int MX = 100000;

int a[MX];

int main() {
	int n;
	scanf("%d", &n);
	
	int k = 1;
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		int p = 1;
		while (a[k - 1] == p) {
			k--;
			p++;
		}
		
		a[k++] = p;
	}
	
	for (int i = 0; i < k; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
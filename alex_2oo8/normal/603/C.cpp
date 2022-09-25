#include<bits/stdc++.h>

using namespace std;

int a[100000];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	int sum = 0;
	if (k % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] < 3) sum ^= a[i];
			else if (a[i] % 2 == 0) sum ^= 1;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (a[i] == 1 || a[i] == 3) {
				sum ^= 1;
				
				continue;
			}
			
			if (a[i] % 2 == 1) continue;
			
			int p = 0;
			while (a[i] % 2 == 0) {
				a[i] /= 2;
				p++;
			}
			
			if (a[i] == 1) {
				if (p > 1) sum ^= 2 - (p % 2);
			}
			else if (a[i] == 3) {
				sum ^= 1 + (p % 2);
			}
			else {
				sum ^= 2 - (p % 2);
			}
		}
	}
	
	if (sum != 0) printf("Kevin\n");
	else printf("Nicky\n");
	
	return 0;
}
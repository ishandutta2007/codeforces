#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int l[MX], r[MX], a[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", l + i);
	for (int i = 0; i < n; i++) ignore = scanf("%d", r + i);
	
	for (int x = n; x > 0; x--) {
		int cntR = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0 && l[i] == 0 && r[i] == 0) {
				cntR++;
				a[i] = x;
			}
		}
		
		int cntL = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == x) cntR--;
			
			if (a[i] == 0) {
				r[i] -= cntR;
				l[i] -= cntL;
				
				if (l[i] < 0 || r[i] < 0) {
					printf("NO\n");
					return 0;
				}
			}
			
			if (a[i] == x) cntL++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
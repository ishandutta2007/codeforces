#include<bits/stdc++.h>

using namespace std;

const int MX = 50;

int p[MX];

int main() {
	int n;
	scanf("%d", &n);
	
	bool have = false;
	for (int i = 0; i < n; i++) {
		p[i] = 0;
		
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			
			p[i] = max(p[i], a);
		}
		
		if (p[i] == n - 1 && have) p[i] = n;
		if (p[i] == n - 1) have = true;
	}
	
	for (int i = 0; i < n; i++) printf("%d ", p[i]);
	printf("\n");
	
	return 0;
}
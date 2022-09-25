#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

char s[MX + 1];
int ans[MX];

int main() {
	ignore = scanf("%s", s);
	
	int n = strlen(s);
	char x = 'b';
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != x) {
			x = s[i];
			ans[i] = 1;
		}
		else {
			ans[i] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	printf("\n");
	
	return 0;
}
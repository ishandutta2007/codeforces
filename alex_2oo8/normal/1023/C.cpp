#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

char s[MX + 1];

int main() {
	int n, k;
	ignore = scanf("%d %d %s", &n, &k, s);
	
	int p = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' && p + b < k) {
			s[p++] = '(';
			b++;
		}
		else if (s[i] == ')' && b > 0) {
			s[p++] = ')';
			b--;
		}
	}
	
	s[p] = 0;
	printf("%s\n", s);
	
	return 0;
}
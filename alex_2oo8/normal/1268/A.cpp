#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

char s[MX + 2];

int main() {
	int n, k;
	ignore = scanf("%d %d %s", &n, &k, s);
	
	int state = 0;
	for (int i = k; i < n; i++)
		if (s[i] != s[i - k]) {
			if (state == 0) {
				state = s[i] < s[i - k] ? 1 : -1;
			}
			s[i] = s[i - k];
		}
	
	if (state >= 0) {
		printf("%d\n%s\n", n, s);
		return 0;
	}
	
	int i = k - 1;
	while (i >= 0 && s[i] == '9') {
		s[i] = '0';
		i--;
	}
	
	if (i == -1) {
		s[0] = '1';
		fill(s + 1, s + k, '0');
		n++;
	}
	else {
		s[i]++;
	}
	
	for (int i = k; i < n; i++) s[i] = s[i - k];
	s[n] = 0;
	
	printf("%d\n%s\n", n, s);
	
	return 0;
}
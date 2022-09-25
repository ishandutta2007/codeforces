#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

char s[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		ignore = scanf("%s", s);
		
		int n = strlen(s);
		
		int sum = 0, zero = 0, even = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i] - '0';
			if (s[i] == '0') zero++;
			if ((s[i] - '0') % 2 == 0) even++;
		}
		
		printf("%s\n", zero > 0 && even > 1 && sum % 3 == 0 ? "red" : "cyan");
	}
	
	return 0;
}
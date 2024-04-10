#include <bits/stdc++.h>

using namespace std;

const int MX = 42;

char s[MX], t[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d %s", &n, s);
		
		memcpy(t, s, n);
		sort(t, t + n);
		
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) k++;
		}
		
		printf("%d\n", k);
	}
	
	return 0;
}
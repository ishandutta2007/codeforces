#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

char s[MX + 1];

int main() {
	ignore = scanf("%s", s);
	
	int n = strlen(s);
	long long vv = 0, vvo = 0, ans = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'o') {
			vvo += vv;
		}
		else if (s[i - 1] == 'v') {
			vv++;
			ans += vvo;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
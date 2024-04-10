#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

char s[MX + 1];

int main() {
	scanf(" %s", s);
	
	long long n = 0;
	char c = '0';
	for (int i = 0; s[i]; i++) {
		n *= 10;
		n += c - '0';
		c = s[i];
	}
	
	unsigned long long ans = (unsigned long long)(n - 1) / 4ull * 16ull;
	if (n % 2 == 0) ans += 7;
	if (c >= 'd') ans += 'f' - c;
	else ans += 3 + c - 'a';
	
	printf("%lld\n", ans + 1);
	
	return 0;
}
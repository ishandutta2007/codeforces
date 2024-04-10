#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n;
char s[55];

int main() {
	scanf("%s", s + 1);
	int m = 0;
	for (char *p = s + 1; *p; p++, n++)
		m += *p == 'a';
	printf("%d\n", min(2 * m - 1, n));
	return 0;
}
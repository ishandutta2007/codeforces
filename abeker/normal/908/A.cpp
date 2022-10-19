#include <bits/stdc++.h>
using namespace std;

bool check(char c) {
	if (isdigit(c))
		return (c - '0') % 2;
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	char s[55];
	scanf("%s", s);
	int sol = 0;
	for (int i = 0; s[i]; i++)
		sol += check(s[i]);
	printf("%d\n", sol);
	return 0;
}
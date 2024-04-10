#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

char s[MX + 1];

int main() {
	int n;
	scanf("%d %s", &n, s);
	
	int l = 0, r = n - 1;
	while (l < n && s[l] == '<') l++;
	while (r >= 0 && s[r] == '>') r--;
	
	printf("%d\n", l + n - 1 - r);
	
	return 0;
}
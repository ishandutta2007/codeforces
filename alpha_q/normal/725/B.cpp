#include <bits/stdc++.h>
 
using namespace std;

const int N = 25;

char s[N];
map <char, int> to;

int main (int argc, char const *argv[]) {
	to['f'] = 1, to['e'] = 2, to['d'] = 3;
	to['a'] = 4, to['b'] = 5, to['c'] = 6;

	scanf("%s", s + 1);
	int l = strlen(s + 1);

	char seat = s[l];
	long long row = 0;

	for (int i = 1; i < l; ++i)
		row *= 10LL, row += (s[i] - '0');
	
	int mod = row % 4LL;
	long long res = ((row - 1)/4LL) * 16LL;

	if (mod == 0 or mod == 2) res += 7;
	res += to[seat];

	printf("%lld\n", res);
	return 0;
}
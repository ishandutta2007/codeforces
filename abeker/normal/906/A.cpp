#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int ALL = (1 << 26) - 1;

int N;
char s[MAXN];

int main() {
	scanf("%d", &N);
	
	int mask = ALL, sol = 0;
	bool ok = false;
	while (N--) {
		char cmd;
		scanf(" %c%s", &cmd, s);
		int tmp = 0;
		for (int i = 0; s[i]; i++)
			tmp |= 1 << s[i] - 'a';
		if (ok && (cmd == '!' || (cmd == '?' && mask != tmp)))
			sol++;
		if (cmd != '!')
			tmp ^= ALL;
		mask &= tmp;
		if (__builtin_popcount(mask) == 1)
			ok = true;
	}
	
	printf("%d\n", sol);
	
	return 0;
}
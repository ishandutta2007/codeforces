#include <bits/stdc++.h>

using namespace std;

char ch[1000010], ch2[1000010];

int S[1000010];

int main() {
	scanf("%s", ch + 1);
	int n = strlen(ch + 1);
	for(int i = 1; i <= n; i++) S[i] = S[i - 1] ^ (ch[i] - '0');
	scanf("%s", ch2 + 1);
	int m = strlen(ch2 + 1);
	int t = 0;
	for(int i = 1; i <= m; i++) t ^= (ch2[i] - '0');
	int ans = 0;
	for(int i = m; i <= n; i++) ans += !(S[i] ^ S[i - m] ^ t);
	printf("%d\n", ans);
	return 0;
}
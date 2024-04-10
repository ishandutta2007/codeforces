#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int N;
char s[MAXN];

int main() {
	scanf("%d%s", &N, s);
	
	int len = 0;
	while (len * (len + 1) / 2 < N)
		len++;

	for (int i = 0; i < len; i++)
		printf("%c", s[i * (i + 1) / 2]);
	puts("");
		
	return 0;
}
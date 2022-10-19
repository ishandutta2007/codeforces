#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];
map <char, int> cnt;

int main() {
	scanf("%d%s", &N, s);
	
	for (int i = 0; i < N; i++)
		cnt[s[i]]++;
	
	int one = min(min(cnt['o'], cnt['n']), cnt['e']);
	int zero = (N - 3 * one) / 4;
	
	while (one--)
		printf("1 ");
	while (zero--)
		printf("0 ");
	puts("");
		
	return 0;
}
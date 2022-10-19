#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, K;
char s[MAXN];
int lvl[30];

int main() {
	scanf("%d%d%s", &N, &K, s);
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		if (i == N - 1 || s[i] != s[i + 1]) {
			lvl[s[i] - 'a'] += cnt / K;
			cnt = 0;
		}
	}
	
	printf("%d\n", *max_element(lvl, lvl + 26));
		
	return 0;
}
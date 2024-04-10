#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int N;
char s[MAXN];
int cnt[1000];

int main() {
	scanf("%d%s", &N, s);
	for (int i = 0; i < N; i++)
		cnt[s[i]]++;
	printf("%d\n", 2 * (min(cnt['U'], cnt['D']) + min(cnt['L'], cnt['R'])));
	return 0;
}
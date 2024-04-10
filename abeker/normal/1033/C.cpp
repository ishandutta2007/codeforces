#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN], pos[MAXN];
bool dp[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);	
		pos[a[i]] = i;
	}
	
	for (int i = N; i; i--)
		for (int j = pos[i] % i; j <= N; j += i)
			if (a[j] > i && !dp[a[j]]) {
				dp[i] = true;
				break;
			}
	
	for (int i = 1; i <= N; i++)
		printf("%c", "BA"[dp[a[i]]]);
	puts("");
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
char s[MAXN];
int a[MAXN], b[MAXN];
int lft[MAXN], rig[MAXN];

int main() {
	scanf("%s", s);	
	N = strlen(s);
	for (int i = 0; i < N; i++) 
		a[i] = a[i + N] = s[i] == 'w';
	
	for (int i = 0; i < 2 * N; i++)
		b[i] = (a[i] + i) % 2;
	
	int ans = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (i && b[i] == b[i - 1])
			lft[i] = lft[i - 1];
		ans = max(ans, ++lft[i]);
	}
	
	for (int i = 2 * N - 1; i >= 0; i--) {
		if (i < 2 * N - 1 && b[i] == b[i + 1])
			rig[i] = rig[i + 1];
		ans = max(ans, ++rig[i]);
	}
	
	for (int i = 0; i < N; i++) 
		if (a[i] != a[i + N - 1])
			ans = max(ans, rig[i] + lft[i + N - 1]);

	printf("%d\n", min(ans, N));
	
	return 0;
}
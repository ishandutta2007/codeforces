#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N;
char s[MAXN];

bool has(int x, int y) {
	for (int i = y - 2; i >= x; i -= 2)
		if (s[i] == s[y] && s[(i + y) / 2] == s[y])
			return true;
	return false;
}

int main() {
	scanf("%s", s);
	N = strlen(s);
	
	long long ans = 0;
	for (int i = 0; i < N; i++) 
		for (int j = i + 2; j < N; j++) 
			if (has(i, j)) {
				ans += N - j;
				break;
			}
	
	printf("%lld\n", ans);
	
	return 0;
}
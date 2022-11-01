#include<bits/stdc++.h>
using namespace std;

int r1[11] = {0, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0};
int r2[11] = {0, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0};
char s[15];
int ans;

int check() {
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= 10; i++) {
		if (s[i] == '1') {
			if (i & 1) s1++;
			else s2++;
		}
		if (s1 + r1[i] < s2 || s2 + r2[i] < s1) return i;
	}
	return 10;
}

void dfs(int x) {
	if (x > 10) {
		ans = min(ans, check());
		return;
	}
	if (s[x] != '?') dfs(x + 1);
	else {
		s[x] = '0';
		dfs(x + 1);
		s[x] = '1';
		dfs(x + 1);
		s[x] = '?';
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		ans = 10;
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
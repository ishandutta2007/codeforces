#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
char s[N], t[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		n = strlen(s + 1);
		m = strlen(t + 1);
		int p = 1, i = 1;
		while (i <= n && s[i] != t[1] || i <= n && s[i] == t[1] && (n - i - m + 1) % 2 == 1) i++;
		for (;i <= n && p <= m; i++) {
			if (s[i] == t[p]) p++;
			else i++;
		}
		if (p > m) puts("YES");
		else puts("NO");
	}
	return 0;
}
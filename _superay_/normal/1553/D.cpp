#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
char s[N], t[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s %s", s + 1, t + 1);
		n = strlen(s + 1);
		m = strlen(t + 1);
		while (n && m) {
			if (s[n] == t[m]) n--, m--;
			else if (n > 1) {
				n -= 2;
			} else {
				break;
			}
		}
		if (!m) puts("YES");
		else puts("NO");
	}
	return 0;
}
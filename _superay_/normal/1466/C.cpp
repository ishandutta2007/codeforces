#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];
char s[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s", s + 1);
		n = strlen(s + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = s[i] - 'a';
			if ((i > 1 && a[i] == a[i - 1]) || (i > 2 && a[i] == a[i - 2])) {
				a[i] = 26;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
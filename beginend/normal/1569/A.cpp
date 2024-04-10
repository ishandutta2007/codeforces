#include<bits/stdc++.h>
using namespace std;

int n;
char s[55];

void solve() {
	for (int i = 1; i < n; i++)
		if (s[i] != s[i + 1]) {
			printf("%d %d\n", i, i + 1);
			return;
		}
	printf("%d %d\n", -1, -1);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char str[45];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, ans = 0;
		scanf("%d", &n);
		scanf(" %s", str);
		string s = str, t = s;
		sort(t.begin(), t.end());
		for (int i = 0; i < n; i++) ans += (s[i] != t[i]);
		printf("%d\n", ans);
	}
	return 0;
}
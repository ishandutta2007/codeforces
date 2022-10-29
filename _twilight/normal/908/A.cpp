#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int ans = 0;
char str[55];
boolean need[256];

inline void init() {
	scanf("%s", str);
}

inline void solve() {
	need['a'] = need['e'] = need['i'] = need['u'] = need['o'] = true;
	need['1'] = need['3'] = need['5'] = need['7'] = need['9'] = true;
	for (char *p = str; *p; p++)
		ans += need[*p];
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
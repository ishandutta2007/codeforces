#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n;
char s[105];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int ans = n;
	for (int i = 1; i < n; i++) {
		if (s[i] ^ s[i + 1]) {
			i++, ans--;
			continue;
		}
	}
	printf("%d\n", ans);
	return 0;
}
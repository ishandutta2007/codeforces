#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, cnt[N * 2];
char s[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s", s);
		n = strlen(s);
		int cur = N;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') cur--;
			cnt[cur]++;
			if (s[i] == '0') cur++;
		}
		cur = N;
		for (int i = 0; i < n; i++) {
			if (cnt[cur] && !(cnt[cur] == 1 && cnt[cur - 1])) putchar('0'), cnt[cur++]--;
			else putchar('1'), cnt[--cur]--;
		}
		putchar('\n');
	}
	return 0;
}
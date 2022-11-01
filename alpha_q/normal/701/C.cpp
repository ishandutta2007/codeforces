#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N], f;
set <char> S;
int n, l, tot, cnt[N], ans = N + N;

int main (int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; ++i) S.insert(s[i]);
	tot = S.size(); S.clear();
	
	l = 1, f = s[1];
	for (int r = 1; r <= n; ++r) {
		S.insert(s[r]);
		cnt[s[r] - 'A']++;
		while (l < r and cnt[f - 'A'] > 1) cnt[f - 'A']--, l++, f = s[l];
		if (S.size() == tot) ans = min(ans, r - l + 1);
	}

	printf("%d\n", ans);
	return 0;
}
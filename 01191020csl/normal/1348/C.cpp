#include<bits/stdc++.h>
using namespace std;
int cnt[26];
void work(int k) {
	int p = 0;
	while (!cnt[p]) ++p;
	if (cnt[p] < k) {
		while (k > 0) k -= cnt[p], ++p;
		putchar(p + 'a' - 1);
		return;
	}
	putchar(p + 'a');
	cnt[p] -= k;
	int vis = 0;
	for (int i = 0; i < 26; i++)
		if (cnt[i]) ++vis;
	if (!vis) return;
	if (vis == 1) {
		while (!cnt[p]) ++p;
		for (int i = 1; i <= (cnt[p]-1)/k+1; i++) putchar(p + 'a');
	}
	else
		for (int i = 0; i < 26; i++)
			for (int j = 1; j <= cnt[i]; j++) putchar(i + 'a');
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		memset(cnt, 0, sizeof(cnt));
		char c=getchar();
		while(!isalpha(c)) c=getchar();
		while (isalpha(c)) ++cnt[c-'a'], c=getchar();
		work(k);
		putchar('\n');
	}
}
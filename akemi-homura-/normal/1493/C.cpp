#include <bits/stdc++.h>
using namespace std;
int n, k, c[26], sum;
char s[100005];
inline void Add(int i) {
	sum -= c[i] % k ? k - c[i] % k : 0;
	c[i]++;
	sum += c[i] % k ? k - c[i] % k : 0;
}
inline void Sub(int i) {
	sum -= c[i] % k ? k - c[i] % k : 0;
	c[i]--;
	sum += c[i] % k ? k - c[i] % k : 0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d %s", &n, &k, s + 1);
		if (n % k != 0) {
			puts("-1");
			continue;
		}
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) c[s[i] - 'a']++;
		sum = 0;
		for (int i = 0; i < 26; i++) sum += c[i] % k ? k - c[i] % k : 0;
		if (!sum) {
			puts(s + 1);
			continue;
		}
		int fnd = 0;
		for (int i = n; i >= 1; i--) {
			Sub(s[i] - 'a');
			for (int x = s[i] - 'a' + 1; x < 26; x++) {
				Add(x);
				if (sum <= n - i) {
					fnd = 1;
					s[i] = x + 'a';
					int tmp = n - i - sum;
					for (int j = i + 1; j <= i + tmp; j++) s[j] = 'a';
					for (int ch = 0; ch < 26; ch++) if (c[ch] % k) {
						int S = k - c[ch] % k;
						for (int j = i + tmp + 1; j <= i + tmp + S; j++) s[j] = ch + 'a';
						tmp += S;
					}
					break;
				}
				Sub(x);
			}
			if (fnd) break;
		}
		if (!fnd) puts("-1");
		else {
			puts(s + 1);
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef bool bolean;

const int N = 1e5 + 5;

#define ll long long

int n;
int sgn[N];
char s1[N], s2[N];
int cnt[N], sum[N];

void print(int p) {
	static int t = 0;
	printf("%d %d\n", p, sgn[p]);
	if (++t == 100000) {
		exit(0);
	}
}

void dfs(int p) {
	if (s1[p + 1] + sgn[p] < '0' || s1[p + 1] + sgn[p] > '9')
		dfs(p + 1);
	print(p);
	s1[p] += sgn[p], s1[p + 1] += sgn[p];
	--cnt[p];
}

int main() {
	scanf("%d", &n);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		sum[i] += s1[i] - '0';
		int c = s2[i] - '0' - sum[i];
		sum[i] += c, sum[i + 1] += c;
		sgn[i] = ((c < 0) ? (-1) : (1));
		cnt[i] = c * sgn[i];
		ans += cnt[i];
	}
	sum[n] += s1[n] - '0';
	if (sum[n] != s2[n] - '0') {
		puts("-1");
	} else {
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++) {
			while (cnt[i]) {
				dfs(i);
			}
		}
	}
	return 0;
}
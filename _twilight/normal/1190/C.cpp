#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, k;
char s[N];

void quit(int id) {
	const static char str[3][30] = {"tokitsukaze", "quailty", "once again"};
	puts(str[id]);
	exit(0);
}

int R0[N], R1[N];
int L0[N], L1[N];

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	
	// tokitsukaze
	boolean aflag = true;
	for (int i = 2; i <= n && aflag; i++)
		if (s[i] != s[i - 1])
			aflag = false;
	if (aflag)
		quit(0);
	
	int st0 = 1, ed0 = n, st1 = 1, ed1 = n;
	while (s[st0] != '0')
		st0++;
	while (s[ed0] != '0')
		ed0--;
	while (s[st1] != '1')
		st1++;
	while (s[ed1] != '1')
		ed1--;
	if (ed0 - st0 < k || ed1 - st1 < k)
		quit(0);
	
	for (int i = 1; i <= n; i++) {
		R0[i] = ((s[i] == '0') ? (i) : (R0[i - 1]));
		R1[i] = ((s[i] == '1') ? (i) : (R1[i - 1]));
	}
	L0[n + 1] = n + 1, L1[n + 1] = n + 1;
	for (int i = n; i; i--) {
		L0[i] = ((s[i] == '0') ? (i) : (L0[i + 1]));
		L1[i] = ((s[i] == '1') ? (i) : (L1[i + 1]));
	}

	// quailty
	for (int l = 1, r = k; r <= n; l++, r++) {
		// paint 0
		int nst1 = ((st1 >= l && st1 <= r) ? (L1[r + 1]) : (st1));
		int ned1 = ((ed1 >= l && ed1 <= r) ? (R1[l - 1]) : (ed1));
		if (ned1 - nst1 >= k)
			quit(2);

		// paint 1
		int nst0 = ((st0 >= l && st0 <= r) ? (L0[r + 1]) : (st0));
		int ned0 = ((ed0 >= l && ed0 <= r) ? (R0[l - 1]) : (ed0));
		if (ned0 - nst0 >= k)
			quit(2);
	}
	quit(1);
	return 0;
}
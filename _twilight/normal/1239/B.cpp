#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

#define pii pair<int, int>

int n;
int s[N];
int orgpos;
char br[N];
pii stk[10];

int main() {
	scanf("%d", &n);
	scanf("%s", br);
	for (int i = 0; i < n; i++) {
		s[i] = ((br[i] == '(') ? 1 : -1) + ((i) ? (s[i - 1]) : 0);
		if (s[i] < s[orgpos]) {
			orgpos = i;
		}
	}
	if (s[n - 1]) {
		puts("0\n1 1");
		return 0;
	}
	orgpos = (orgpos + 1) % n;
	rotate(br, br + orgpos, br + n);
	int ansl = 0, ansr = 0, base = 0;
	for (int i = 0; i < n; i++) {
		s[i] = ((br[i] == '(') ? 1 : -1) + ((i) ? (s[i - 1]) : 0);
		base += !s[i];
	}
	int maxdlt = base;
	for (int i = 0; i < n; i++) {
		int v = s[i];
		if (v > 2)
			continue;
		for (int j = v + 1; j < 3; j++)
			stk[j] = pii(0, -1);
		if (!stk[v].first) {
			stk[v].first = 1;
			stk[v].second = i;
		} else {
			stk[v].first++;
		}
		int t = (v == 2) * base + stk[v].first;
		if (t > maxdlt) {
			ansl = stk[v].second;
			ansr = i + 1;
			maxdlt = t;
//			cerr << v << " " << stk[v].first << " " << stk[v].second << '\n';
		}
	}
	ansr %= n;
 	swap(br[ansl], br[ansr]);
	int ans = 0, sum = 0, mi = 0;
	for (int i = 0; i < n; i++) {
		sum += ((br[i] == '(') ? 1 : -1);
		mi = min(mi, sum);
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ((br[i] == '(') ? 1 : -1);
		ans += (mi == sum);
	}
	printf("%d\n%d %d\n", ans, (ansl + orgpos) % n + 1, (ansr + orgpos) % n + 1);
	return 0;
}
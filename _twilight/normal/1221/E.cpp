#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

int T;
int a, b;
char s[N];

boolean qaq;
int one_time;
vector<int> long_stripe;

void add(int L) {
	if (L < b)
		return;
	if (L < a) {
		qaq = true;
	} else if (L < 2 * b) {
		one_time++;
	} else {
		long_stripe.push_back(L);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		scanf("%s", s + 1);
		int len = 0;
		qaq = false;
		one_time = 0;
		long_stripe.clear();
		for (char *p = s + 1; *p; p++) {
			if (*p == 'X') {
				add(len);
				len = 0;
			} else {
				len++;
			}
		}
		add(len);
		if (qaq) {
			puts("NO");
		} else if (long_stripe.size() >= 2) {
			puts("NO");
		} else if (long_stripe.size() == 1) {
			int L = long_stripe.back();
			boolean qwq = false;
			for (int l = 0; l <= L - a && !qwq; l++) {
				int r = L - l - a;
				if (b <= l && l < a) continue;
				if (b <= r && r < a) continue;
				if (l >= 2 * b) continue;
				if (r >= 2 * b) continue;
				int ncnt = one_time + (a <= l && l < 2 * b) + (a <= r && r < 2 * b);
				if (!(ncnt & 1)) {
					qwq = true;
				}
			}
			if (qwq) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else {
			puts((one_time & 1) ? ("YES") : ("NO"));
		}
	}
	return 0;
}
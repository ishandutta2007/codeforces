#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 105;

#define pii pair<int, int>

int T;
int c[26];
char s[N];

void pc(pii par) {
	for (int _ = par.second; _; _--)
		putchar(par.first + 'a');
}

void solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
		c[s[i] - 'a']++;
	vector<pii> C;
	for (int i = 0; i < 26; i++) {
		if (c[i]) {
			C.emplace_back(i, c[i]);
		}
	}
	if (C.size() == 1) {
		pc(C[0]);
		putchar('\n');
	} else if (C.size() == 2) {
		if (C[0].first + 1 == C[1].first) {
			puts("No answer");
		} else {
			pc(C[0]), pc(C[1]);
			putchar('\n');
		}
	} else if (C.size() == 3) {
		if (C[0].first + 1 == C[1].first) {
			if (C[1].first + 1 == C[2].first) {
				puts("No answer");
			} else {
				pc(C[0]), pc(C[2]), pc(C[1]);
				putchar('\n');
			}
		} else {
			pc(C[1]), pc(C[0]), pc(C[2]);
			putchar('\n');
		}
	} else if (C.size() == 4) {
		pc(C[2]), pc(C[0]), pc(C[3]), pc(C[1]);
		putchar('\n');
	} else {
		for (int i = 0; i < C.size(); i += 2)
			pc(C[i]);
		for (int i = 1; i < C.size(); i += 2)
			pc(C[i]);
		putchar('\n');
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
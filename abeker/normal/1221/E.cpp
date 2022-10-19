#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int A, B;
char s[MAXN];
int large, between, all;

void load() {
	scanf("%d%d%s", &A, &B, s);
}

void change_segment(int len, int v) {
	if (len >= 2 * B)
		large += v;
	if (len >= B && len < A)
		between += v;
	if (len >= B)
		all += v;
}

bool solve() {
	large = between = all = 0;
	int N = strlen(s), last = 0;
	vector <int> segments;
	for (int i = 1; i <= N; i++)
		if (s[i] != s[i - 1]) {
			if (s[i - 1] == '.') {
				segments.push_back(i - last);
				change_segment(i - last, 1);
			}
			last = i;
		}
	
	for (auto it : segments) {
		change_segment(it, -1);
		for (int i = 0; i <= it - A; i++) {
			change_segment(i, 1);
			change_segment(it - A - i, 1);
			if (!between && !large && !(all % 2))
				return true;
			change_segment(i, -1);
			change_segment(it - A - i, -1);
		}
		change_segment(it, 1);
	}
	
	return false;
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		load();
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}
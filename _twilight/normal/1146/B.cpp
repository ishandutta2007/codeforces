#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n;
int idx1;
int idx[100005];
char s[100005], t[100005];

int main() {
	int cnta = 0, cntna = 0;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] != 'a') {
			t[++cntna] = s[i];
			idx[cntna] = i;
		} else {
			++cnta;
			idx1 = i;
		}
	}
	if (cntna & 1) {
		puts(":(");
		return 0;
	}
	for (int i = 1; i <= (cntna >> 1); i++)
		if (t[i] != t[i + (cntna >> 1)]) {
			puts(":(");
			return 0;
		}
	int pos = max(idx1, idx[cntna >> 1]);
	s[pos + 1] = 0;
	int x = 0;
	for (int i = 1; i <= pos; i++) {
		x += s[i] != 'a';
	}
	if (x == (cntna >> 1)) {
		puts(s + 1);
	} else {
		puts(":(");
	}
	return 0;
}
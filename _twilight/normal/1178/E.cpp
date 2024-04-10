#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;

int n;
char s[N];
int h[3], suf[N][3], pre[N][3];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		s[i] -= 'a';
		memcpy(pre[i], h, sizeof(h));
		h[s[i]] = i;
	}
	memcpy(pre[n + 1], h, sizeof(h));
	h[0] = h[1] = h[2] = n + 1;
	for (int i = n; ~i; i--) {
		memcpy(suf[i], h, sizeof(h));
		h[s[i]] = i;
	}
	int L = 0, R = n + 1;
	vector<char> ansL, ansR;
	while (L < R) {
		int d = n << 1, c = -1, dc = n << 1;
		for (int i = 0; i < 3; i++) {
			if (suf[L][i] < R && pre[R][i] > L && suf[L][i] <= pre[R][i]) {
				dc = suf[L][i] - L + R - pre[R][i];
				if (dc < d) {
					d = dc, c = i;
				}
			}
		}
		if (c == -1) {
			break;
		}
		L = suf[L][c], R = pre[R][c];
		ansL.push_back('a' + c);
		if (L ^ R) {
			ansR.push_back('a' + c);
		}
	}
	for (int i = 0; i < ansL.size(); i++) {
		putchar(ansL[i]);
	}
	for (int i = (signed) ansR.size() - 1; ~i; i--) {
		putchar(ansR[i]);
	}
	return 0;
}
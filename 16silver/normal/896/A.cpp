#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

long long len[100010];
long long infty = 3000000000000000000LL;

int main() {
	char c1[300] = "What are you doing at the end of the world? Are you busy? Will you save us?";
	char c2[300] = "What are you doing while sending \"";
	char c3[300] = "\"? Are you busy? Will you send \"";
	char c4[300] = "\"?";
	int i, q, n, t, j;
	long long k;
	len[0] = 75LL;
	for (i = 1; i <= 100000; i++) {
		len[i] = 2 * len[i - 1] + 68LL;
		if (len[i] > infty) len[i] = infty;
	}
	scanf("%d", &q);
	for (t = 0; t < q; t++) {
		scanf("%d %I64d", &n, &k);
		if (len[n] < k) printf(".");
		else {
			for (j = n - 1; j >= 0; j--) {
				if (k < 35LL) {
					printf("%c", c2[k - 1LL]);
					break;
				}
				else if (k < 35LL + len[j]) {
					k -= 34LL;
				}
				else if (k < 67LL + len[j]) {
					printf("%c", c3[k - len[j] - 35LL]);
					break;
				}
				else if (k < 67LL + 2LL * len[j]) {
					k -= 66LL + len[j];
				}
				else {
					printf("%c", c4[k - 67LL - 2LL * len[j]]);
					break;
				}
			}
			if (j == -1) printf("%c", c1[k - 1]);
		}
	}
}
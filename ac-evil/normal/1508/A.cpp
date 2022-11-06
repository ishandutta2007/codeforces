#include <bits/stdc++.h>
const int N = 100005;
int T, n; char s1[N * 2], s2[N * 2], s3[N * 2];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s%s%s", &n, s1, s2, s3);
		// 11111 len = L
		// x + (2n - x) + (2n - y)
		// 4n - y <= 3n
		// y >= n
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 0; i < 2 * n; i++)
			cnt1 += s1[i] == '1', cnt2 += s2[i] == '1', cnt3 += s3[i] == '1';
		int flag = (cnt1 >= n) + (cnt2 >= n) + (cnt3 >= n);
		if (flag > 1) {
			// 1
			if (cnt1 < n) std::swap(s1, s3);
			if (cnt2 < n) std::swap(s2, s3);
			int p1 = 0, p2 = 0, p = 0;
			while (p1 < n * 2 && p2 < n * 2) {
				if (s1[p1] == '0' || s2[p2] == '0') {
					putchar('0');
					if (s1[p1] == '0') p1++;
					if (s2[p2] == '0') p2++;
				} else putchar('1'), p1++, p2++;
				p++;
			}
			// printf("%d %d %d\n", p1, p2, p);
			while (p1 < n * 2) printf("%c", s1[p1++]), p++;
			while (p2 < n * 2) printf("%c", s2[p2++]), p++;
			while (p < n * 3) putchar('0'), p++;
		} else {
			// 0
			if (cnt1 >= n) std::swap(s1, s3);
			if (cnt2 >= n) std::swap(s2, s3);
			int p1 = 0, p2 = 0, p = 0;
			while (p1 < n * 2 && p2 < n * 2) {
				if (s1[p1] == '1' || s2[p2] == '1') {
					putchar('1');
					if (s1[p1] == '1') p1++;
					if (s2[p2] == '1') p2++;
				} else putchar('0'), p1++, p2++;
				p++;
			}
			// printf("\n%s\n%s", s1, s2);
			while (p1 < n * 2) printf("%c", s1[p1++]), p++;
			while (p2 < n * 2) printf("%c", s2[p2++]), p++;
			while (p < n * 3) putchar('0'), p++;
		}
		puts("");
	}
	return 0;
}
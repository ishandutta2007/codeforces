#include<bits/stdc++.h>
using namespace std;

const int N = 20005;

int n;
char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		bool flag = 0;
		for (int i = n / 2 + 1; i <= n; i++)
			if (s[i] == '0') {
				printf("%d %d %d %d\n", 1, i, 1, i - 1);
				flag = 1;
				break;
			}
		if (!flag) {
			if (s[n / 2] == '1') printf("%d %d %d %d\n", n / 2, n - 1, n / 2 + 1, n);
			else printf("%d %d %d %d\n", n / 2, n, n / 2 + 1, n);
		}
	}
	return 0;
}
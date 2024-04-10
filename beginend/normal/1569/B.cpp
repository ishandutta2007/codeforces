#include<bits/stdc++.h>
using namespace std;

const int N = 55;

int n, ans[N][N];
char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		vector<int> a;
		for (int i = 1; i <= n; i++)
			if (s[i] == '2') a.push_back(i);
		int tot = a.size();
		if (tot == 1 || tot == 2) {
			puts("NO");
			continue;
		}
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < tot - 1; i++)
			ans[a[i]][a[i + 1]] = 1;
		if (tot) ans[a[tot - 1]][a[0]] = 1;
		puts("YES");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				if (i == j) putchar('X');
				else if (ans[i][j]) putchar('+');
				else if (ans[j][i]) putchar('-');
				else putchar('=');
			puts("");
		}
	}
	return 0;
}
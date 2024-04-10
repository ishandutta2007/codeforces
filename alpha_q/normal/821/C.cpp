#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

char cmd[7];
int n, it, ans;
int st[N], top;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n + n; ++i) {
		scanf("%s", cmd);
		if (cmd[0] == 'a') {
			scanf("%d", st + ++top);
			continue;
		}
		++it;
		if (top == 0) {
			continue;
		}
		if (st[top] == it) {
			--top;
			continue;
		}
		++ans, top = 0;
	}
	printf("%d\n", ans);
	return 0;
}
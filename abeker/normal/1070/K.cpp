#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, K;
int a[MAXN];

void bye() {
	puts("No");
	exit(0);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}
	
	if (a[N] % K)
		bye();
	
	vector <int> ans;
	ans.push_back(0);
	for (int i = 1; i <= N; i++)
		if (a[i] == a[N] / K * (int)ans.size())
			ans.push_back(i);
	
	if (ans.size() != K + 1)
		bye();
	
	puts("Yes");
	for (int i = 1; i <= K; i++)
		printf("%d ", ans[i] - ans[i - 1]);
	puts("");
	
	return 0;
}
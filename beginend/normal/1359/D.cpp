#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], s[N], sta[N], mn[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
	int top = 1, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int w = s[i - 1];
		while (top && a[i] >= sta[top]) w = min(w, mn[top]), top--;
		sta[++top] = a[i];
		mn[top] = w;
		for (int j = 1; j <= top; j++)
			ans = max(ans, s[i] - mn[j] - sta[j]);
	}
	printf("%d\n", ans);
	return 0;
}
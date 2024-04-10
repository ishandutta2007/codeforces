#include <bits/stdc++.h>
using namespace std;
string s[1000010];
vector<int> g[1000010];
int a[1000010];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		g[i].resize(m + 5);
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= m; j++)
			g[i][j] = (s[i][j - 2] == 'X' && s[i - 1][j - 1] == 'X');
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[j] += g[i][j];
	for(int i = 1; i <= m; i++)
		a[i] += a[i - 1];
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		if(a[r] - a[l] > 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
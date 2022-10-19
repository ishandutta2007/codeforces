#include <bits/stdc++.h>
using namespace std;
int n;
char inp[500010];
int perfect, pos[500010], neg[500010];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %s", inp);
		int len = strlen(inp);
		int mn = 0;
		int am = 0;
		for (int j = 0; j < len; j++)
		{
			if (inp[j] == '(') am++;
			else am--;
			mn = min(mn, am);
		}
		if (mn < 0 && am <= 0 && mn != am) continue;
		am = max(am, 0);
		if (!am && !mn)
		{
			perfect++;
		}
		else if (!am)
		{
			neg[-mn]++;
		}
		else if (!mn)
		{
			pos[am]++;
		}
	}
	int ans = perfect/2;
	for (int i = 0; i <= 500000; i++)
	{
		ans += min(pos[i], neg[i]);
	}
	printf("%d\n", ans);
}
#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		int m = 0;
		for(int i = 1; i <= n;)
		{
			int j = i;
			while(s[j - 1] == s[i - 1] && i <= n)
				i++;
			a[++m] = i - j;
		}
		int ans = 0, i = 1, j = 1;
		while(i <= m)
		{
			if(j < i)
				j = i;
			while(j <= m && a[j] == 1)
				j++;
			if(j > m)
				j = m--;
			else
				a[j]--;
			i++;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int coun[300];
bool workeditout;
char str[100010];
int ans;
int lastseen[100010];
int main()
{
	int n;
	scanf("%d", &n);
	for (int k = 1; k < n; k++)
	{
		char a;
		scanf(" %c", &a);
		if (a == '.')
		{
			scanf(" %s", str);
			int len = strlen(str);
			for (int i = 0; i < len; i++)
			{
				if (lastseen[str[i]] != k) coun[str[i]] = -999999999;
				lastseen[str[i]] = k;
			}
		}
		else if (a == '!')
		{
			if (workeditout) ans++;
			scanf(" %s", str);
			int len = strlen(str);
			for (int i = 0; i < len; i++)
			{
				if (lastseen[str[i]] != k) coun[str[i]]++;
				lastseen[str[i]] = k;
			}
		//	printf("\n");
		}
		else if (a == '?')
		{
			if (workeditout) ans++;
			scanf(" %c", &a);
			coun[a] = -999999999;
		}
		int mx = -1;
		int mxam = 0;
		for (int j = 'a'; j <= 'z'; j++)
		{
			if (coun[j] > mx)
			{
				mx = coun[j];
				mxam = 0;
			}
			else if (coun[j] == mx)
			{
				mxam++;
			}
		}
		if (!mxam) 
		{
		//	printf("%d %d %d\n", k, mx, mxam);
			workeditout = true;
		}
	}
	printf("%d\n", ans);
}
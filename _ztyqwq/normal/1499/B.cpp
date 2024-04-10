#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		s = " " + s;
		int pre = -1, now = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] - '0' != now)
			{
				if(i - pre >= 2)
					pre = i;
				else
				{
					if(now == 1)
					{
						printf("NO\n");
						goto no;
					}
					now = 1;
				}
			}
		}
		printf("YES\n");
		no:;
	}
	return 0;
}
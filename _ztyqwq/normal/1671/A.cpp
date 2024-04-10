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
		s += ('a' + 'b' - s[n - 1]);
		int tot = 0, flag = false;
		for(int i = 0; i <= n; i++)
		{
			if(!i || s[i] == s[i - 1])
				tot++;
			else
			{
				if(tot == 1)
				{
					flag = true;
					break;
				}
				tot = 1;
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
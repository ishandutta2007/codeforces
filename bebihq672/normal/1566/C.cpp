#include<bits/stdc++.h>
using namespace std;

char s1[101010], s2[101010], s[101010];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
		int n;
		scanf("%d", &n);
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);

		int ans = 0, last = -1;
		for(int i = 1; i <= n; i++)
		{
			if(s1[i] != s2[i])
			{
				ans += 2;
				last = -1;
			}
			else if(s1[i] == '0')
			{
				if(last == 1)
				{
					ans += 2;
					last = -1;
				}
				else
				{
					ans += 1;
					last = 0;
				}
			}
			else if(s1[i] == '1')
			{
				if(last == 0)
				{
					ans += 1;
					last = -1;
				}
				else
				{
					last = 1;
				}
			}
		}
		printf("%d\n", ans);
    }
    return 0;
}
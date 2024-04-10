#include <bits/stdc++.h>

using namespace std;

int t, n, odp, x, y;
char s[100001];
pair <pair <int, int>, pair <int, int> > sr[100001];

int main()
{
	scanf("%d", &t);
	for(int i=0; i<t; ++i)
	{
		scanf("%s", s+1);
		n=strlen(s+1);
		x=0;
		y=0;
		for(int i=1; i<=n; ++i)
		{
			if(s[i]=='N')
			{
				sr[i]={{x, y}, {x, y+1}};
				++y;
			}
			if(s[i]=='S')
			{
				sr[i]={{x, y-1}, {x, y}};
				--y;
			}
			if(s[i]=='E')
			{
				sr[i]={{x, y}, {x+1, y}};
				++x;
			}
			if(s[i]=='W')
			{
				sr[i]={{x-1, y}, {x, y}};
				--x;
			}
			
		}
		sort(sr+1, sr+1+n);
		odp=5;
		for(int i=2; i<=n; ++i)
		{
			if(sr[i]==sr[i-1])
			{
				++odp;
			}
			else
			{
				odp+=5;
			}
		}
		printf("%d\n", odp);
	}
	return 0;
}
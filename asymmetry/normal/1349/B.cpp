#include <bits/stdc++.h>

using namespace std;

int gh, n, k, a, b, c;
int t[100001];
int r[100001];
set <int> s;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d%d", &n, &k);
		b=1;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i]);
			if(t[i]==k)
			{
				b=0;
			}
		}
		if(b)
		{
			printf("no\n");
			continue;
		}
		if(n==1)
		{
			printf("yes\n");
			continue;
		}
		for(int i=1; i<=n; ++i)
		{
			r[i]=r[i-1];
			if(t[i]>=k)
			{
				++r[i];
			}
			else
			{
				--r[i];
			}
		}
		s.clear();
		s.insert(0);
		a=0;
		for(int i=2; i<=n; ++i)
		{
			if(s.lower_bound(-r[i]+1)!=s.end())
			{
				a=1;
				//printf("(((%d)))\n", i);
				break;
			}
			s.insert(-r[i-1]);
		}
		if(a)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
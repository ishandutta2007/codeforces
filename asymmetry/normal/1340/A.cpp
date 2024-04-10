#include <bits/stdc++.h>

using namespace std;

int gh, n, b, a;
int t[100001];
int p[100001];
bitset <100011> bt;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i]);
			p[t[i]]=i;
			bt[i]=0;
		}
		bt[n+1]=1;
		b=0;
		for(int i=1; i<=n; ++i)
		{
			a=p[i];
			while(!bt[a])
			{
				i=t[a];
				bt[a]=1;
				if(!bt[a+1])
				{
					if(t[a+1]!=t[a]+1)
					{
						b=1;
						printf("NO\n");
						break;
					}
				}
				++a;
			}
			if(b)
			{
				break;
			}
			
		}
		if(!b)
		{
			printf("YES\n");
		}
	}
	return 0;
}
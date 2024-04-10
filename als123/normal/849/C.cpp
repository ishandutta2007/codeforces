#include<cstdio>
#include<cstring>
int s[1000],cnt;
int k;
int main()
{
	while (true)
	{
		cnt++;
		s[cnt]=cnt*(cnt-1)/2;
		if (s[cnt]>=100000) break;
	}
	scanf("%d",&k);
	if (k==0) 
	{
		printf("a");
		return 0;
	}
	int lalal=0;
	while (k>0)
	{
		for (int u=cnt;u>=1;u--)
		{
			if (s[u]<=k)
			{
				k-=s[u];
				for (int i=1;i<=u;i++) printf("%c",lalal+'a');
				break;
			}
		}
		lalal++;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,taxi; 
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		if(n%2==1)
		{
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
				{
					if((i+j)%2==1)printf("1 ");
					else printf("-1 ");
				}
			puts("");
			continue;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				if(i%2==1)
				{
					printf("0 ");
					for(int j=i+2;j<=n;j++)
					{
						if((i+j)%2==0)printf("1 ");
						else printf("-1 ");
					}
				}
				else
				{
					for(int j=i+1;j<=n;j++)
					{
						if((i+j)%2==0)printf("1 ");
						else printf("-1 ");
					}
				}
			}
			puts("");
			continue;
		}
	}
	return 0;
}
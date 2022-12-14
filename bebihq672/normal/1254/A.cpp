#include<bits/stdc++.h>
using namespace std;

char ans[62];

char s[101][101];

int w[101][101];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		int N=n;
		for(int i=1;i<=r;i++)
			scanf("%s",s[i]+1);
		
		for(int i=0;i<10;i++)
			ans[i]='0'+i;
		for(int i=0;i<26;i++)
			ans[i+10]='a'+i;
		for(int i=0;i<26;i++)
			ans[i+36]='A'+i;	
		
		int m=0;
		for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(s[i][j]=='R')
				m++;
		
		int tmp=0,now=0;
		for(int i=1;i<=r;i++)
		{
			if(i&1)
			for(int j=1;j<=c;j++)
			{
				w[i][j]=min(N-1,now);
				if(s[i][j]=='R')
				{
					tmp++;
					if((tmp+1)*n>m)
					{
						now++;
						m-=tmp;
						n--;
						tmp=0;
					}
				}
			}
			else
			for(int j=c;j>=1;j--)
			{
				w[i][j]=min(N-1,now);
				if(s[i][j]=='R')
				{
					tmp++;
					if((tmp+1)*n>m)
					{
						now++;
						m-=tmp;
						n--;
						tmp=0;
					}
				}
			}
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
				printf("%c",ans[w[i][j]]);
			puts("");
		}
		
	}
	return 0;
}
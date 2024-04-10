#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
void solve(int w1,int w2,int w3,int m)
{
	puts("YES");
	if(m%6==4)
	{
		for(int i=1;i<=m+1;i++)
		{
			if(i%3==1)printf("%d ",w3);
			else if(i%3==2)printf("%d ",w1);
			else printf("%d ",w2);
		}
	}else if(m%6==0)
	{
		for(int i=1;i<=m+1;i++)
		{
			if(i%3==1)printf("%d ",w2);
			else if(i%3==2)printf("%d ",w3);
			else printf("%d ",w1);
		}
	}else
	{
		for(int i=1;i<=m+1;i++)
		{
			if(i%3==1)printf("%d ",w1);
			else if(i%3==2)printf("%d ",w2);
			else printf("%d ",w3);
		}
	}
	puts("");
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		if(m&1)
		{
			puts("YES");
			for(int i=1;i<=m+1;i++)
			{
				if(i&1)printf("1 ");
				else printf("2 ");
			}
			puts("");
			continue;
		}
		int w1=0,w2=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			if(i!=j&&s[i][j]==s[j][i])w1=i,w2=j;
		if(w1&&w2)
		{
			puts("YES");
			for(int i=1;i<=m+1;i++)
			{
				if(i&1)printf("%d ",w1);
				else printf("%d ",w2);
			}
			puts("");
			continue;
		}
		if(n==2)
		{
			puts("NO");
			continue;
		}
		if(m==2)
		{
			puts("YES");
			if(s[1][2]==s[2][3])puts("1 2 3");
			else if(s[2][3]==s[3][1])puts("2 3 1");
			else puts("3 1 2");
			continue;
		}
		if(s[1][2]==s[2][3]&&s[2][3]==s[3][1])
		{
			puts("YES");
			for(int i=1;i<=m+1;i++)
			{
				if(i%3==0)printf("1 ");
				else if(i%3==1)printf("2 ");
				else printf("3 ");
			}
			puts("");
			continue;
		}
		if(s[1][2]==s[2][3])solve(1,2,3,m);
		else if(s[2][3]==s[3][1])solve(2,3,1,m);
		else solve(3,1,2,m);
	}
	return 0;
}
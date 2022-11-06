#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int x,y,taxi,totx,toty,flag;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0;
		x=read(),y=read(),totx=0,toty=0;
		if(x>y)
		{
			puts("NO");
			continue;
		}
		else if(x==y)
		{
			puts("YES");
			continue;
		}
		else
		{
			for(int i=0;i<=30;i++)
			{
				if((x&(1<<i))!=0)totx++;
				if((y&(1<<i))!=0)toty++;
				if(totx<toty)flag=1;
			}
			if(!flag)puts("YES");
			else puts("NO");
			continue;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9;
int taxi,n,cnt[N],num[N],x,flag; 
int main()
{
	taxi=read();
	for(int i=1;i<=taxi;i++)
	{
		flag=0;
		n=read();
		for(int i=1;i<=n;i++)cnt[i]=num[i]=0;
		for(int i=1;i<=n;i++)
		{
			x=read();
			cnt[x]++;num[x]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==1)
			{
				flag=1;
				printf("%d\n",num[i]);
				break;
			}
		}
		if(!flag)
		{
			puts("-1");
		}
	}
	return 0;
}
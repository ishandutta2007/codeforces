#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,a[59],ans,c[69],now=1,cnt=0;
int main()
{
	taxi=read();
	now=1;
	for(int i=1;i<=8;i++)c[now+1]=cnt++,now=now*2;
	for(int i=1;i<=60;i++)
		if(c[i]==0)c[i]=c[i-1];
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<n;i++)
		{
			int k=(max(a[i],a[i+1])-1)/min(a[i],a[i+1])+1;
			ans+=c[k];
		}
		cout<<ans<<endl;
	}
	return 0;
}
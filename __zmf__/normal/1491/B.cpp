#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=109;
int ans,n,u,v,a[N],tot[10],opt,x,taxi,flag,flag2;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0,flag2=0;
		n=read(),u=read(),v=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i+1])flag=1;
			if(a[i]-a[i+1]>=2||a[i+1]-a[i]>=2)flag2=1;
		}
		if(flag2)ans=0;
		else if(!flag)ans=v+min(u,v);
		else ans=min(u,v);
		printf("%d\n",ans);
	}
	return 0;
}
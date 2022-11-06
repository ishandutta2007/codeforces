#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,d[109];
int n,a[109];
inline void dfs(int l,int r,int now)
{
	if(l>r)return ;
	if(l==r)
	{
		d[l]=now;return ;
	}
	int pos,maxn=0;
	for(int i=l;i<=r;i++)
		if(maxn<a[i])pos=i,maxn=a[i];
	d[pos]=now;
	dfs(l,pos-1,now+1);
	dfs(pos+1,r,now+1);
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		dfs(1,n,0);
		for(int i=1;i<=n;i++)printf("%d ",d[i]);
		puts("");
	}
	return 0;
}
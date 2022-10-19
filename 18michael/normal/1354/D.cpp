#include<cstdio>
int n,q,ans;
int arr[1000002]={},lg[1000002];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x,int d)
{
	while(x<=n)arr[x]+=d,x+=lowbit(x);
}
inline int find(int now,int x,int t)
{
	if(!t)return x<=arr[now+1]? now+1:n+1;
	if(now+(1<<(t-1))>n || x<=arr[now+(1<<(t-1))])return find(now,x,t-1);
	return find(now+(1<<(t-1)),x-arr[now+(1<<(t-1))],t-1);
}
int main()
{
	scanf("%d%d",&n,&q),lg[0]=-1;
	for(int i=1;i<=n;++i)lg[i]=lg[(i>>1)]+1;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),modify(x,1);
	for(int x;q--;)
	{
		scanf("%d",&x);
		if(x>0)modify(x,1);
		else x=-x,modify(find(0,x,lg[n]+1),-1);
	}
	ans=find(0,1,lg[n]+1),printf("%d",ans>n? 0:ans);
	return 0;
}
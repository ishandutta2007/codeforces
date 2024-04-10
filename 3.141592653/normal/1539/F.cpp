#include<bits/stdc++.h>
int n;
struct segTree
{
	int maxv[1111111],tad[1111111];
	void clear()
	{
		memset(maxv,0,sizeof maxv);
		memset(tad,0,sizeof tad);
	}
	void upd(int l,int r,int d,int p=1,int pl=1,int pr=n)
	{
		if(l>pr||pl>r)return;
		if(l<=pl&&pr<=r){tad[p]+=d,maxv[p]+=d;return;}
		int pm=(pl+pr)>>1;
		upd(l,r,d,p<<1,pl,pm),upd(l,r,d,p<<1|1,pm+1,pr),
		maxv[p]=std::max(maxv[p<<1],maxv[p<<1|1])+tad[p]; 
	}
	int ask(int l,int r,int p=1,int pl=1,int pr=n)
	{
		if(l>pr||pl>r)return -1e9;
		if(l<=pl&&pr<=r)return maxv[p];
		int pm=(pl+pr)>>1;
		return 
		std::max(ask(l,r,p<<1,pl,pm),ask(l,r,p<<1|1,pm+1,pr))+tad[p];
	}
}T;
int a[1111111];
int prefixDless[1111111],prefixDgreater[1111111],
suffixDless[1111111],suffixDgreater[1111111];
std::vector<int>v[1111111];
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)scanf("%d",a+i),v[a[i]].push_back(i);
	for(i=1;i<=n;i++)T.upd(1,i,-1);
	for(i=1;i<=n;i++)
	{
		for(int t:v[i])T.upd(1,t,2);
		for(int t:v[i])if(t>1)
			prefixDless[t]=T.ask(1,t)-T.ask(t,t);
	}
	T.clear();
	for(i=1;i<=n;i++)T.upd(1,i,-1);
	for(i=n;i;i--)
	{
		for(int t:v[i])T.upd(1,t,2);
		for(int t:v[i])if(t>1)
			prefixDgreater[t]=T.ask(1,t)-T.ask(t,t);
	}
	T.clear();
	for(i=1;i<=n;i++)T.upd(i,n,-1);
	for(i=1;i<=n;i++)
	{
		for(int t:v[i])T.upd(t,n,2);
		for(int t:v[i])if(t<n)
			suffixDless[t]=T.ask(t,n)-T.ask(t,t);
	}
	T.clear();
	for(i=1;i<=n;i++)T.upd(i,n,-1);
	for(i=n;i;i--)
	{
		for(int t:v[i])T.upd(t,n,2);
		for(int t:v[i])if(t<n)
			suffixDgreater[t]=T.ask(t,n)-T.ask(t,t);
	}
	//for(i=1;i<=n;i++)
	//	printf("%d %d %d %d\n"
	//	,prefixDless[i],prefixDgreater[i],
	//	suffixDless[i],suffixDgreater[i]);
	for(i=1;i<=n;i++)
	{
		printf("%d ",std::max
		((prefixDless[i]+suffixDless[i])>>1,
		(prefixDgreater[i]+suffixDgreater[i]+1)>>1));
	}
	puts("");
}
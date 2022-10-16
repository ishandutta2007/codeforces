#include<bits/stdc++.h>
int n,q,a[1111111];
const int MAXV=1000010;
std::vector<int>primeDivs[1111111];
struct dsu
{
	int fa[1111111];
	int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
	void merge(int x,int y)
	{x=rt(x),y=rt(y);if(x!=y)fa[x]=y;}
}U;
void ins(int x)
{for(int t:primeDivs[x])U.merge(x,t);}
typedef long long ll;
std::unordered_map<ll,bool>Vis;
bool findv(int x,int y)
{
	if(x>y){int t=x;x=y,y=t;}
	return Vis[x*10000000ll+y];
}
void insd(int x,int y)
{
	for(int s:primeDivs[x])
		for(int t:primeDivs[x])
		{
			int a=U.rt(s),b=U.rt(t);
			if(a<b)Vis[a*10000000ll+b]=1;
		}
	for(int s:primeDivs[x])
		for(int t:primeDivs[y])
		{
			int a=U.rt(s),b=U.rt(t);
			if(a<b)Vis[a*10000000ll+b]=1;
		}
	for(int s:primeDivs[y])
		for(int t:primeDivs[y])
		{
			int a=U.rt(s),b=U.rt(t);
			if(a<b)Vis[a*10000000ll+b]=1;
		}
	for(int s:primeDivs[y])
		for(int t:primeDivs[x])
		{
			int a=U.rt(s),b=U.rt(t);
			if(a<b)Vis[a*10000000ll+b]=1;
		}
}
bool vs[1111111];
int main()
{
	scanf("%d%d",&n,&q);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",a+i),vs[a[i]]=1;
	for(i=2;i<=MAXV;i++)
		if(!primeDivs[i].size())
			for(ii=i;ii<=MAXV;ii+=i)
				primeDivs[ii].push_back(i);
	for(i=1;i<=n;i++)ins(a[i]);
	for(i=1;i<=n;i++)insd(a[i],a[i]+1);
	for(i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),x=U.rt(a[x]),y=U.rt(a[y]);
		if(x==y)puts("0");
		else if(findv(x,y))puts("1");
		else puts("2");
	} 
}
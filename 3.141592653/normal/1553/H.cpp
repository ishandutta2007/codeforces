#include<bits/stdc++.h>
using std::min;
using std::swap;
int s[11111111][2],dl[11111111],dr[11111111],minv[11111111];
int sz[11111111];
int k,n;
int rv[1<<21];
int a[1<<21];
int cp=1;
void pushu(int p)
{
	if(s[p][0]&&s[p][1])
		dl[p]=dl[s[p][0]],dr[p]=dr[s[p][1]],
		minv[p]=min(dr[s[p][0]]+dl[s[p][1]]+1,
		min(minv[s[p][0]],minv[s[p][1]]));
	else if(s[p][0])
		dl[p]=dl[s[p][0]],dr[p]=dr[s[p][0]]+sz[p],
		minv[p]=minv[s[p][0]];
	else if(s[p][1])
		dr[p]=dr[s[p][1]],dl[p]=dl[s[p][1]]+sz[p],
		minv[p]=minv[s[p][1]];
}
void ins(int x,int p=1,int i=k-1)
{
	if(i<0)
	{
		dl[p]=dr[p]=0,minv[p]=1e9;
		return;
	}
	sz[p]=1<<i;
	int d=(x>>i)&1;
	if(!s[p][d])s[p][d]=++cp;
	ins(x-(d<<i),s[p][d],i-1),pushu(p);
}
void init()
{
	for(register int i=1;i<=n;i++)ins(a[i]);
}
void flip(int dep,int p=1,int i=k-1)
{
	if(!p)return;
	if(i==dep){swap(s[p][0],s[p][1]),pushu(p);return;}
	flip(dep,s[p][0],i-1),flip(dep,s[p][1],i-1),pushu(p);
}
int T;
int recalc(int S)
{
	for(register int i=0;i<k;i++)
		if(((S^T)>>i)&1)flip(i);
	T=S;
	return minv[1];
}
int ans[1<<21];
int main()
{
	scanf("%d%d",&n,&k);
	for(register int i=1;i<=n;i++)
		scanf("%d",a+i);
	init();
	for(register int i=1;i<(1<<k);i++)
		rv[i]=(rv[i>>1]>>1)|((i&1)?(1<<(k-1)):0);
	for(register int i=0;i<(1<<k);i++)
		ans[rv[i]]=recalc(rv[i]);
	for(register int i=0;i<(1<<k);i++)
		printf("%d ",ans[i]);
	puts("");
}
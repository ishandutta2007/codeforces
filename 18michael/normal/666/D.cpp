#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int Test_num,mxd;
bool ok;
typedef pair<int,int> P;
int id[4];
bool u[4];
P a[4],ans[4],tmp[4];
inline int dis(P a,P b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
inline void update(int o)
{
	int t=-1;
	for(int i=1;i<4;++i)
		if(tmp[i]!=tmp[0])
		{
			t=0;
			break;
		}
	if(!(~t))return ;
	for(int i=0;i<4;++i)
	{
		if(a[i].first!=tmp[id[i]].first && a[i].second!=tmp[id[i]].second)return ;
		t=max(t,dis(a[i],tmp[id[i]]));
	}
	if(t<mxd)
	{
		mxd=t,ok=o;
		for(int i=0;i<4;++i)ans[i]=tmp[id[i]];
	}
}
inline void dfs(int x,int o)
{
	if(x==4)return update(o);
	for(int i=0;i<4;++i)if(!u[i])u[id[x]=i]=1,dfs(x+1,o),u[i]=0;
}
inline void calc(int o)
{
	int t,mn,mx;
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)if(j!=i && a[i].first==a[j].first && a[i].second<=a[j].second)
			for(int k=0;k<4;++k)if(k!=i && k!=j)
				for(int l=0;l<4;++l)if(l!=i && l!=j && l!=k && a[k].first==a[l].first && a[k].second<=a[l].second)
				{
					t=abs(a[i].first-a[k].first),mn=min(min(a[i].second,a[j].second-t),min(a[k].second,a[l].second-t));
					mx=max(max(a[i].second,a[j].second-t),max(a[k].second,a[l].second-t));
					tmp[id[i]=0]=P(a[i].first,((mx+mn+1)>>1)),tmp[id[j]=1]=P(a[i].first,((mx+mn+1)>>1)+t);
					tmp[id[k]=2]=P(a[k].first,((mx+mn+1)>>1)),tmp[id[l]=3]=P(a[k].first,((mx+mn+1)>>1)+t),update(o);
				}
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)if(j!=i && a[i].first==a[j].first)
			for(int k=0;k<4;++k)if(k!=i && k!=j)
				for(int l=0;l<4;++l)if(l!=i && l!=j && l!=k)
				{
					t=abs(a[i].first-a[k].first),tmp[0]=P(a[k].first,a[l].second-t),tmp[1]=P(a[k].first,a[l].second);
					tmp[2]=P(a[i].first,a[l].second-t),tmp[3]=P(a[i].first,a[l].second),dfs(0,o);
					tmp[0]=P(a[k].first,a[l].second+t),tmp[1]=P(a[k].first,a[l].second);
					tmp[2]=P(a[i].first,a[l].second+t),tmp[3]=P(a[i].first,a[l].second),dfs(0,o);
					t=abs(a[k].second-a[l].second),tmp[0]=P(a[i].first,a[k].second),tmp[1]=P(a[i].first,a[l].second);
					tmp[2]=P(a[i].first-t,a[k].second),tmp[3]=P(a[i].first-t,a[l].second),dfs(0,o);
					tmp[0]=P(a[i].first,a[k].second),tmp[1]=P(a[i].first,a[l].second);
					tmp[2]=P(a[i].first+t,a[k].second),tmp[3]=P(a[i].first+t,a[l].second),dfs(0,o);
				}
}
inline void solve()
{
	mxd=inf;
	for(int i=0;i<4;++i)scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=0;i<4;++i)
		for(int j=i+1;j<4;++j)if(j!=i)
			for(int k=0;k<4;++k)if(k!=i && k!=j)
				for(int l=k+1;l<4;++l)if(l!=i && l!=j && l!=k && abs(a[i].first-a[j].first)==abs(a[k].second-a[l].second))
				{
					tmp[0]=P(a[i].first,a[k].second),tmp[1]=P(a[j].first,a[k].second);
					tmp[2]=P(a[i].first,a[l].second),tmp[3]=P(a[j].first,a[l].second),dfs(0,0);
				}
	calc(0);
	for(int i=0;i<4;++i)swap(a[i].first,a[i].second);
	calc(1);
	if(mxd==inf)puts("-1");
	else
	{
		printf("%d\n",mxd);
		for(int i=0;i<4;++i)
		{
			if(ok)swap(ans[i].first,ans[i].second);
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}
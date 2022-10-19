#include<bits/stdc++.h>
using namespace std;
int n,t,m,tot,las,Test_num;
int a[100002],id[100002];
bool u[100002];
vector<int> vec[502];
typedef pair<int,int> P;
P mx;
P f[100002];
inline P merge(P a,P b)
{
	return a.first>b.first? a:b;
}
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	P a[100002];
	inline void clear()
	{
		for(int i=1;i<=n;++i)a[i]=P(0,0);
	}
	inline void modify(int x,P d)
	{
		while(x<=n)a[x]=merge(a[x],d),x+=lowbit(x);
	}
	inline P query(int x)
	{
		P res=P(0,0);
		while(x)res=merge(res,a[x]),x-=lowbit(x);
		return res;
	}
}S;
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
inline void ins(int x)
{
	if(!x)return ;
	ins(f[x].second),vec[t].push_back(a[x]),u[x]=0;
}
inline void solve()
{
	for(scanf("%d",&n),t=las=tot=0,m=1;(m+1)*(m+2)/2<=n;++m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i,u[i]=1;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)swap(a[id[i]],las),a[id[i]]=a[id[i-1]]+(a[id[i]]!=las);
	for(;tot<n;--m)
	{
		vec[++t].clear(),mx=P(0,0),S.clear();
		for(int i=1;i<=n;++i)if(u[i])f[i]=S.query(a[i]-1),S.modify(a[i],P(++f[i].first,i)),mx=merge(mx,P(f[i].first,i));
		if(mx.first>m)
		{
			tot+=mx.first,ins(mx.second);
			continue;
		}
		for(--t;tot<n;)
		{
			vec[++t].clear(),las=n+1;
			for(int i=1;i<=n;++i)if(u[i] && a[i]<las)vec[t].push_back(a[i]),las=a[i],u[i]=0,++tot;
		}
		break;
	}
	printf("%d\n",t);
	for(int i=1;i<=t;++i)
	{
		printf("%d ",vec[i].size());
		for(int j=0;j<vec[i].size();++j)printf("%d%c",vec[i][j],j+1==vec[i].size()? '\n':' ');
	}
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}
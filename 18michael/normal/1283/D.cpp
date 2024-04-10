#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define inf 2000000000
using namespace std;
int n,m;LL lmn,rmn,amn=0;
int d[200002],e[200002],ans[200002];
typedef pair<int,int> P;P lp,rp;
priority_queue<P,vector<P>,greater<P> > lpq,rpq;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int a,int b)
{
	return a<b? 1:0;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(d[i]);
	sort(d+1,d+n+1,cmp),e[0]=-inf,e[n]=inf;
	for(int i=1;i<n;++i)e[i]=((d[i]+d[i+1])>>1);
	for(int i=1;i<=n;++i)
	{
		if(d[i]-1>e[i-1])lpq.push(P(1,i));
		if(d[i]+1<=e[i])rpq.push(P(1,i));
	}
	for(int i=1,j;i<=m;++i)
	{
		if(!lpq.empty())lp=lpq.top(),lmn=lp.first;else lmn=inf;
		if(!rpq.empty())rp=rpq.top(),rmn=rp.first;else rmn=inf;
		if(lmn<rmn)
		{
			amn+=lmn,ans[i]=d[j=lp.second]-lmn,lpq.pop();
			if(ans[i]-1>e[j-1])lpq.push(P(lmn+1,j));
		}
		else
		{
			amn+=rmn,ans[i]=d[j=rp.second]+rmn,rpq.pop();
			if(ans[i]+1<=e[j])rpq.push(P(rmn+1,j)); 
		}
	}
	printf("%lld\n",amn);
	for(int i=1;i<=m;++i)printf("%d ",ans[i]);
	return 0;
}
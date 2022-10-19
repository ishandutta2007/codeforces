#include<cstdio>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
int n,m,X;LL t=0;
int rt[300002],x[300002],y[300002];
LL a[300002];
typedef pair<LL,int> P;P p;
priority_queue<P,vector<P>,less<P> > pq;
vector<P> vec[300002];
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	scanf("%d%d%d",&n,&m,&X);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),t+=a[i],pq.push(P(a[i],i)),rt[i]=i;
	if(t<1LL*(n-1)*X)return 0&puts("NO");puts("YES");
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[x].push_back(P(y,i)),vec[y].push_back(P(x,i));
	for(int i=1,v;;++i)
	{
		do p=pq.top(),pq.pop();while(p.first!=a[p.second]);
		x[i]=p.second;
		while(1)
		{
			getroot(v=vec[x[i]].back().first);
			if(x[i]!=rt[v])break;vec[x[i]].pop_back();
		}
		y[i]=rt[v],printf("%d\n",vec[x[i]].back().second),vec[x[i]].pop_back();
		if(i+1==n)break;
		while(1)
		{
			getroot(v=vec[y[i]].back().first);
			if(y[i]!=rt[v])break;vec[y[i]].pop_back();
		}
		if(vec[x[i]].size()>vec[y[i]].size())swap(x[i],y[i]);
		while(!vec[x[i]].empty())
		{
			getroot(v=vec[x[i]].back().first);
			if(y[i]!=rt[v])vec[y[i]].push_back(P(rt[v],vec[x[i]].back().second));
			vec[x[i]].pop_back();
		}
		a[y[i]]+=a[x[i]]-X,a[x[i]]=-1,rt[x[i]]=y[i],pq.push(P(a[y[i]],y[i]));
	}
	return 0;
}
#include<cstdio>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
int M,n,m,n1,m1,a,b,head,tail;
int st[1002];
int h[1002][1002],g[1002][1002];
LL p[1002][1002];
bool u[1000002]={};
vector<int> vecx,vecy;
vector<LL> vecz;
typedef pair<LL,int> P;P t;
priority_queue<P,vector<P>,greater<P> > pq;
inline int num(int x,int y)
{
	return (x-1)*M+y-1;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b),M=m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)scanf("%d",&h[i][j]),p[i][j]=p[i][j-1]+h[i][j];
		for(int j=1;j<=m;++j)p[i][j]=p[i][j]+p[i-1][j];
	}
	for(int i=1;i<=n;++i)
	{
		head=1,tail=0;
		for(int j=1;j<b;++j)
		{
			while(head<=tail && h[i][st[tail]]>=h[i][j])--tail;
			st[++tail]=j;
		}
		for(int j=b;j<=m;++j)
		{
			while(head<=tail && h[i][st[tail]]>=h[i][j])--tail;
			while(head<=tail && j-st[head]>=b)++head;
			st[++tail]=j,g[i][j-b+1]=h[i][st[head]];
		}
	}
	m-=b-1;
	for(int i=1;i<=m;++i)
	{
		head=1,tail=0;
		for(int j=1;j<a;++j)
		{
			while(head<=tail && g[st[tail]][i]>=g[j][i])--tail;
			st[++tail]=j;
		}
		for(int j=a;j<=n;++j)
		{
			while(head<=tail && g[st[tail]][i]>=g[j][i])--tail;
			while(head<=tail && j-st[head]>=a)++head;
			st[++tail]=j,h[j-a+1][i]=g[st[head]][i];
		}
	}
	n-=a-1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			pq.push(P(p[i+a-1][j+b-1]+p[i-1][j-1]-p[i+a-1][j-1]-p[i-1][j+b-1]-1LL*a*b*h[i][j],num(i,j)));
	while(!pq.empty())
	{
		t=pq.top(),pq.pop();if(u[t.second])continue;
		n1=t.second/M+a,m1=(t.second%M)+b,vecx.push_back(n1-a+1),vecy.push_back(m1-b+1),vecz.push_back(t.first);
		for(int i=max(n1-2*a+2,1);i<=n1;++i)
			for(int j=max(m1-2*b+2,1);j<=m1;++j)
				u[num(i,j)]=1;
	}
	printf("%d\n",vecx.size());
	for(int i=0;i<vecx.size();++i)printf("%d %d %lld\n",vecx[i],vecy[i],vecz[i]);
	return 0;
}
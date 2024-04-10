#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,n1,t,v,x,y,mx,mxnum,disnum,Test_num;
int p[100002],num[100002],nx[100002],la[100002],ans[100002];
bool u[100002];typedef pair<int,int> P;P pt;
priority_queue<P,vector<P>,less<P> > pq,ept;
struct aaa
{
	int to,p;
}q[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline bool cmp(aaa a,aaa b)
{
	return a.p<b.p? 1:0;
}
inline void print()
{
	puts("YES"),t=0;
	for(int i=1;i<=n;++i)if(!ans[i])q[++t]=(aaa){i,p[i]};
	sort(q+1,q+t+1,cmp);
	for(int i=1,j=1+pq.top().first;i<=t;++i,j=(j%t)+1)
	{
		if(q[i].p!=q[j].p)ans[q[i].to]=q[j].p;
		else ans[q[i].to]=disnum;
	}
	t=y-x;
	for(int i=1;i<=n;++i)
	{
		if(ans[i]==p[i] || ans[i]==disnum)printf("%d",ans[i]);
		else if(t)printf("%d",ans[i]),--t;else printf("%d",disnum);
		printf("%c",i==n? '\n':' ');
	}
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(x),read(y),n1=n+1,mx=0,pq=ept;
		for(int i=1;i<=n1;++i)num[i]=nx[i]=la[i]=ans[i]=0;
		for(int i=1;i<=n;++i)
		{
			read(p[i]);
			if((++num[p[i]])>mx)mx=num[p[i]],mxnum=p[i];
			nx[i]=la[p[i]],la[p[i]]=i;
		}
		for(int i=1;i<=n1;++i)if(num[i])pq.push(P(num[i],i));
		for(int i=n1;i;--i)if(!num[i]){disnum=i;break;}
		for(int i=1;i<=x;++i)
		{
			pt=pq.top(),pq.pop(),--pt.first,v=pt.second,ans[la[v]]=p[la[v]],la[v]=nx[la[v]];
			if(pt.first)pq.push(pt);
		}
		if(!pq.empty() && pq.top().first-(n-y)>(y-x)/2)puts("NO");
		else print();
	}
	return 0;
}
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int n1,n2,n3,n4,m1,m2,m3,t,ans=inf;
int a[150002],b[150002],c[150002],d[150002],f[150002],f1[150002];
vector<int> vec1[150002],vec2[150002],vec3[150002];
priority_queue<int,vector<int>,greater<int> > pq,ept;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dp(int n4,int d[],int n3,int c[],vector<int> vec3[])
{
	for(int i=1;i<=n4;++i)f[i]=d[i];
	sort(f+1,f+n4+1);
	for(int i=1;i<=n3;++i)
	{
		pq=ept,t=1;
		for(int j=0;j<vec3[i].size();++j)pq.push(d[vec3[i][j]]);
		while(!pq.empty() && pq.top()==f[t])pq.pop(),++t;
		if(t>n4)f1[i]=c[i]+inf;else f1[i]=c[i]+f[t];
	}
}
int main()
{
	read(n1),read(n2),read(n3),read(n4);
	for(int i=1;i<=n1;++i)read(a[i]);
	for(int i=1;i<=n2;++i)read(b[i]);
	for(int i=1;i<=n3;++i)read(c[i]);
	for(int i=1;i<=n4;++i)read(d[i]),f1[i]=d[i];
	read(m1);for(int i=1,x,y;i<=m1;++i)read(x),read(y),vec1[x].push_back(y);
	read(m2);for(int i=1,x,y;i<=m2;++i)read(x),read(y),vec2[x].push_back(y);
	read(m3);for(int i=1,x,y;i<=m3;++i)read(x),read(y),vec3[x].push_back(y);
	dp(n4,d,n3,c,vec3);for(int i=1;i<=n3;++i)c[i]=f1[i];
	dp(n3,c,n2,b,vec2);for(int i=1;i<=n2;++i)b[i]=f1[i];
	dp(n2,b,n1,a,vec1);for(int i=1;i<=n1;++i)a[i]=f1[i];
	for(int i=1;i<=n1;++i)ans=min(ans,a[i]);
	printf("%d",ans==inf? -1:ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,t,t1,cnt=0;
int p[1000002],q[1000002],q1[1000002],la[1000002]={};
bool vis[1000002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(p[i]);
	for(int i=1,x,y;i<=n;++i)
		if(!vis[i])
		{
			for(vis[i]=t=1,x=p[i];x!=i;x=p[x],++t)vis[x]=1;
			if(t&1)
			{
				for(t1=1,x=p[i];t1<=t;x=p[x],++t1)q1[((2*t1-1)%t)+1]=x;
				for(t1=1;t1<=t;++t1)q[q1[t1]]=q1[(t1%t)+1];
				continue;
			}
			if(!la[t]){la[t]=i,++cnt;continue;}
			for(t1=1,x=p[la[t]],la[t]=0,--cnt;t1<=t;x=p[x],++t1)q1[2*t1-1]=x;
			for(t1=1,x=p[i];t1<=t;x=p[x],++t1)q1[2*t1]=x;
			for(t1=1,t<<=1;t1<=t;++t1)q[q1[t1]]=q1[(t1%t)+1];
		}
	if(cnt)return 0&puts("-1");
	for(int i=1;i<=n;++i)printf("%d%c",q[i],i==n? '\n':' ');
	return 0;
}
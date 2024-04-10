#include<bits/stdc++.h>
using namespace std;
int t,t1,n,m,mx=0;
int cnt[1000002]={},cnt1[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int dis(int x,int y,int X,int Y)
{
	return abs(x-X)+abs(y-Y);
}
inline bool check(int x,int y)
{
	if(x<1 || x>n || y<1 || y>m)return 0;
	for(int i=0;i<t;++i)cnt1[i]=cnt[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if((--cnt1[dis(x,y,i,j)])<0)
				return 0;
	return 1;
}
int main()
{
	read(t);if(t==1)return 0&printf("1 1\n1 1");
	for(int i=1,x;i<=t;++i)read(x),mx=max(mx,x),++cnt[x];
	for(int i=1;i<t;++i)if(cnt[i]!=4*i){t1=i;break;}
	for(int i=1;i*i<=t;++i)
		if(!(t%i))
		{
			n=i,m=t/i;
			if(check(t1,n+m-mx-t1))return 0&printf("%d %d\n%d %d",n,m,t1,n+m-mx-t1);
			if(check(n+m-mx-t1,t1))return 0&printf("%d %d\n%d %d",n,m,n+m-mx-t1,t1);
		}
	return 0&puts("-1");
}
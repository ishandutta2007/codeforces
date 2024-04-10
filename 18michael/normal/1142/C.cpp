#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,st_t=1;
int st[100002];
struct aaa
{
	LL x,y;
}p[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return ((a.x==b.x)? (a.y<b.y):(a.x<b.x));
}
inline aaa mns(aaa a,aaa b)
{
	return (aaa){a.x-b.x,a.y-b.y};
}
inline LL dot(aaa a,aaa b)
{
	return a.x*b.y-a.y*b.x;
}
int main()
{
	st[1]=1,read(n);
	for(int i=1;i<=n;++i)read(p[i].x),read(p[i].y),p[i].y-=p[i].x*p[i].x;
	sort(p+1,p+n+1,cmp);
	while(st[1]<n && p[st[1]+1].x==p[st[1]].x)++st[1];
	for(int i=st[1]+1;i<=n;++i)
	{
		while(st_t>1 && dot(mns(p[i],p[st[st_t]]),mns(p[st[st_t-1]],p[st[st_t]]))>=0)--st_t;
		st[++st_t]=i;
	}
	return 0&printf("%d",st_t-1);
}
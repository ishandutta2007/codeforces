#include<bits/stdc++.h>
#define LL long long
#define inf 3000000000000000000LL
using namespace std;
int n;LL t;
int id[1000002],cnt[1000002]={};
LL a[1000002],l[1000002],r[1000002],b[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
int main()
{
	read(n),read(t),b[0]=-inf;
	for(int i=1;i<=n;++i)read(a[i]),a[i]+=t,id[i]=i,l[i]=-inf,r[i]=inf;
	sort(id+1,id+n+1,cmp);
	for(int i=1,x;i<=n;++i)
	{
		read(x),l[x]=max(l[x],a[i]),++cnt[i],--cnt[x];
		if(x<n)r[x]=min(r[x],a[x+1]-1);
	}
	for(int i=1;i<n;++i)
		if((cnt[i]+=cnt[i-1])>0)
			l[i]=max(l[i],a[i+1]);
	for(int i=1;i<=n;++i)
	{
		b[i]=max(b[i-1]+1,l[i]);
		if(b[i]>r[i])return 0&puts("No");
	}
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%lld%c",b[i],i==n? '\n':' ');
	return 0;
}
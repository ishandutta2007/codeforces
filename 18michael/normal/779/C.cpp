#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k;LL ans=0;
int a[200002],b[200002],id[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]-b[x]<a[y]-b[y];
}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;++i)read(a[i]),id[i]=i;
	for(int i=1;i<=n;++i)read(b[i]);
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=k;++i)ans+=a[id[i]];
	for(int i=k+1;i<=n;++i)ans+=min(a[id[i]],b[id[i]]);
	return 0&printf("%lld",ans);
}
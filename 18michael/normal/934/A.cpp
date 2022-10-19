#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;LL mx;
LL a[52],b[52],c[4];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]);sort(a+1,a+n+1);
	for(int i=1;i<=m;++i)read(b[i]);sort(b+1,b+m+1);
	c[0]=a[1]*b[1],c[1]=a[1]*b[m],c[2]=a[n]*b[1],c[3]=a[n]*b[m],mx=max(max(c[0],c[1]),max(c[2],c[3]));
	if(c[0]==mx || c[1]==mx)c[0]=a[2]*b[1],c[1]=a[2]*b[m];else c[2]=a[n-1]*b[1],c[3]=a[n-1]*b[m];
	return 0&printf("%lld",max(max(c[0],c[1]),max(c[2],c[3])));
}
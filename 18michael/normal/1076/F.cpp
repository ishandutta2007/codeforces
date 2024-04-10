#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k;LL res;
LL a[300002],b[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;++i)read(b[i]),b[i]+=b[i-1];
	for(int i=1;i<=n;++i)res=a[i],a[i]=a[i]*k-b[i],b[i]=b[i]*k-res;
	res=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]-res<-k)return 0&puts("NO");
		res=max(res,a[i]);
	}
	res=0;
	for(int i=1;i<=n;++i)
	{
		if(b[i]-res<-k)return 0&puts("NO");
		res=max(res,b[i]);
	}
	return 0&puts("YES");
}
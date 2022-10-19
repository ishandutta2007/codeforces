#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,t=0;
LL res=0,ans=0;
LL c[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int a,int b)
{
	return a>b? 1:0;
}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;++i)read(c[i]);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if((res+=c[i])<0)
		{
			t=n-i+1,c[i]=res;
			break;
		}
		if(i<n)ans+=res;
	}
	for(int i=n-k-1;i>=n-t+1;--i)ans+=c[i]*((n-i)/(k+1));
	return 0&printf("%lld",ans);
}
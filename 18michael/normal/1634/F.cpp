#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,q,mod,cnt=0;
char ch;
LL a[300012],f[300012];
inline void add(int x,LL y)
{
	cnt-=!a[x],cnt+=!((a[x]+=y)%=mod);
}
int main()
{
	scanf("%d%d%d",&n,&q,&mod),f[1]=1;
	for(int i=2;i<=n;++i)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i+1]);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),(a[i+1]-=x)%=mod;
	for(int i=(n+=3);i>1;--i)cnt+=!((a[i]-=a[i-1]+a[i-2])%=mod);
	for(int x,y;q--;)
	{
		do ch=getchar();while(ch!='A' && ch!='B');
		ch=(ch=='A'? 1:-1),scanf("%d%d",&x,&y),add(x+1,ch),add(y+2,(-f[y-x]-f[y-x+1])*ch),add(y+3,-f[y-x+1]*ch),puts(cnt==n-1? "YES":"NO");
	}
	return 0;
}
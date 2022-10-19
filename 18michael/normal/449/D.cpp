#include<bits/stdc++.h>
#define LL long long
#define Mx 1048576
#define Mx1 19
#define mod 1000000007
using namespace std;
int n,ans;
int a[1048576],cnt[1048576],pw[1048576];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int add(int x,int y)
{
	if((x+=y)<=-mod)x+=mod;
	if(x>=mod)x-=mod;
	return x;
}
int main()
{
	read(n),pw[0]=1;
	for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]],pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=0;i<=Mx1;++i)
		for(int j=0;j<Mx;j+=(1<<(i+1)))
			for(int k=j;k<j+(1<<i);++k)
				cnt[k]+=cnt[k+(1<<i)];
	for(int i=1;i<Mx;++i)cnt[i]=pw[cnt[i]]-1;
	for(int i=0;i<=Mx1;++i)
		for(int j=0;j<Mx;j+=(1<<(i+1)))
			for(int k=j;k<j+(1<<i);++k)
				cnt[k]=add(cnt[k],-cnt[k+(1<<i)]);
	ans=pw[n]-1;
	for(int i=1;i<=Mx;++i)ans=add(ans,-cnt[i]);
	return 0&printf("%d",add(ans,mod));
}
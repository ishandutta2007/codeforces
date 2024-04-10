#include<cstdio>
#define mod 998244353
int n,Test_num,sum,ans;
int a[100002],t[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void solve()
{
	read(n),sum=ans=0;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x;i<=n;++i)
	{
		t[i]=1;
		for(int j=i-1;j;--j)
		{
			if(t[j]==(x=(a[j]+a[j+1]/t[j+1]-1)/(a[j+1]/t[j+1])))break;
			sum=(sum+1LL*j*(x-t[j]))%mod,t[j]=x;
		}
		ans=(ans+sum)%mod;
	}
	printf("%d\n",(ans+mod)%mod);
}
int main()
{
	read(Test_num);
	while(Test_num--)solve();
	return 0;
}
#include<bits/stdc++.h>
#define Mx 29
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,vec_t=0,t,tot,Test_num;LL ans;
int l[200002],r[200002],v[200002],cnt[200002],vec[400002];
LL pw[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num),pw[0]=1;
	for(int i=1;i<=200000;++i)pw[i]=(pw[i-1]<<1)%mod;
	while(Test_num--)
	{
		read(n),read(m),ans=0;
		for(int i=1;i<=m;++i)read(l[i]),read(r[i]),read(v[i]);
		for(int i=Mx;~i;--i)
		{
			while(vec_t)cnt[vec[vec_t]]=0,--vec_t;
			for(int j=1;j<=m;++j)
				if(!((v[j]>>i)&1))
				{
					if(!cnt[l[j]])vec[++vec_t]=l[j];
					if(!cnt[r[j]+1])vec[++vec_t]=r[j]+1;
					++cnt[l[j]],--cnt[r[j]+1];
				}
			t=tot=0;for(int j=1;j<=n;++j)tot+=cnt[j],t+=(!tot);
			ans=(ans+(((t? pw[t-1]:0)*pw[n-t])%mod)*pw[i])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
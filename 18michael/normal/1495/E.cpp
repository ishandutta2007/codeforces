#include<cstdio>
#define LL long long
int n,m;LL res=0,Ans=1;LL sum[2]={};
int p[200002],k[200002],b[200002],w[200002],t[5000002],a[5000002];
LL ans[5000002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}

const int mod = 1e9 + 7;
int seed = 0, base = 0;
int rnd()
{
	int r = seed;
	seed = (1ll * seed * base + 233) % mod;
	return r;
}
void generate(int m, int p[], int k[], int b[], int w[], int t[], int a[])
{
	p[0] = 0;
	for (int i = 1; i <= m; ++i) {
		seed = b[i], base = w[i];
		for (int j = p[i - 1] + 1; j <= p[i]; ++j) {
			t[j] = rnd() % 2, a[j] = rnd() % k[i] + 1;
		}
	}
	return;
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=m;++i)read(p[i]),read(k[i]),read(b[i]),read(w[i]);
	generate(m,p,k,b,w,t,a);
	for(int i=1;i<=n;++i)sum[t[i]]+=a[i];
	if(sum[t[1]]<=sum[t[1]^1])
	{
		for(int i=1;i<=n;++i)
		{
			if(t[i]==t[1]){res+=a[i],ans[i]=a[i];continue;}
			if(res<=a[i])a[i]-=res,ans[i]+=res,res=0;
			else res-=a[i],ans[i]+=a[i],a[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			if(t[i]==t[1])continue;
			if(res<=a[i])a[i]-=res,ans[i]+=res,res=0;
			else res-=a[i],ans[i]+=a[i],a[i]=0;
		}
	}
	else
	{
		--a[1],++ans[1];
		for(int i=1;i<=n;++i)
		{
			if(t[i]!=t[1]){res+=a[i],ans[i]=a[i];continue;}
			if(res<=a[i])a[i]-=res,ans[i]+=res,res=0;
			else res-=a[i],ans[i]+=a[i],a[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			if(t[i]!=t[1])continue;
			if(res<=a[i])a[i]-=res,ans[i]+=res,res=0;
			else res-=a[i],ans[i]+=a[i],a[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			if(t[i]!=t[1])continue;
			if(res<=a[i])a[i]-=res,ans[i]+=res,res=0;
			else res-=a[i],ans[i]+=a[i],a[i]=0;
		}
	}
	for(int i=1;i<=n;++i)Ans=(Ans*(((ans[i]^(1LL*i*i))+1)%mod))%mod;
	return 0&printf("%lld",Ans);
}
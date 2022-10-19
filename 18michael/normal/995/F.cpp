#include<cstdio>
#include<vector>
#define LL long long
#define mod 1000000007
using namespace std;
int n,d,ans=0;
LL res=1,res1;
int pw[6002];
int f[3002][3002],g[3002][3002];
vector<int> son[3002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void dfs(int x,int fa)
{
	for(int i=0;i<=n;++i)g[x][i]=1;
	for(int i=0,v;i<son[x].size();++i)
		if((v=son[x][i])!=fa)
		{
			dfs(v,x);
			for(int j=0;j<=n;++j)g[x][j]=(1LL*g[x][j]*f[v][j])%mod;
		}
	f[x][0]=g[x][0];
	for(int i=1;i<=n;++i)f[x][i]=(f[x][i-1]+g[x][i])%mod;
}
int main()
{
	read(n),read(d);
	for(int i=2,x;i<=n;++i)read(x),son[x].push_back(i);
	dfs(1,0);if(d<=n+1)return 0&printf("%d",f[1][d-1]);
	for(int i=0;i<=n;++i)res=(res*(d-i-1))%mod;
	for(int i=0;i<=2*n;++i)pw[i]=Pow(i-n,mod-2);
	for(int i=0;i<=n;++i)
	{
		res1=(res*Pow(d-i-1,mod-2))%mod;
		for(int j=0;j<=n;++j)if(j!=i)res1=(res1*pw[i-j+n])%mod;
		ans=(ans+res1*f[1][i])%mod;
	}
	return 0&printf("%d",(ans+mod)%mod);
}
#include<cstdio>
#include<map>
#include<vector>
void emax(int&x,int y){x<y?x=y:0;}
typedef long long ll;
const ll mod=1e9+7;
int qpow(int x,int k)
{int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
int k,n,m;
std::map<int,int>M,R;
int l[1111111],r[1111111],f[1111111],t[1111111];
int x[1111111];
int lim1[1111111],lim0[1111111];
ll dp[1111111][3];
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	register int i;
	M[0]=M[k]=1;
	for(i=1;i<=n;i++)scanf("%d%d",l+i,r+i),M[l[i]-1]=M[r[i]]=1;
	for(i=1;i<=m;i++)scanf("%d%d",f+i,t+i),M[f[i]-1]=M[t[i]]=1;
	int Id=0;
	for(auto&p:M)x[p.second=++Id]=p.first;
	for(i=1;i<=n;i++)
		emax(lim1[M[r[i]]],M[l[i]-1]);
	for(i=1;i<=m;i++)
		emax(lim0[M[t[i]]],M[f[i]-1]);
	ll S0=0,S1=0,S=1;
	int L0=0,L1=0;
	for(i=2;i<=Id;i++)
	{
		int le=x[i]-x[i-1],c2=qpow(2,le)-2;
		ll St=(S+S0+S1)*c2%mod;
		dp[i-1][0]=(S1+S)%mod,dp[i-1][1]=(S0+S)%mod;
		(S0+=dp[i-1][0])%=mod,(S1+=dp[i-1][1])%=mod;
		while(L0<=lim0[i])(S0+=mod-dp[L0][0])%=mod,L0++;
		while(L1<=lim1[i])(S1+=mod-dp[L1][1])%=mod,L1++;
		S=St;
	}printf("%lld\n",(S+S0+S1)%mod);
}
/*
Please don't let me down.
*/
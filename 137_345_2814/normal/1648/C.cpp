#include<cstdio>
using namespace std;
#define N 200500
#define mod 998244353
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int n,m,fr[N],ifr[N],s[N],t[N],su[N],as,nw;
struct BIT{
	int tr[N];
	void add(int x,int v){for(int i=x;i<=2e5;i+=i&-i)tr[i]+=v;}
	int que(int x){int as=0;for(int i=x;i;i-=i&-i)as=as+tr[i];return as;}
}tr;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),su[s[i]]++;
	for(int i=1;i<=m;i++)scanf("%d",&t[i]);
	fr[0]=ifr[0]=1;for(int i=1;i<=2e5;i++)fr[i]=1ll*i*fr[i-1]%mod,ifr[i]=pw(fr[i],mod-2);
	nw=1;
	for(int i=1;i<=2e5;i++)tr.add(i,su[i]),nw=1ll*nw*ifr[su[i]]%mod;
	for(int i=1;i<=m;i++)
	{
		as=(as+1ll*nw*fr[n-i]%mod*tr.que(t[i]-1))%mod;
		if(!su[t[i]])break;
		nw=1ll*nw*su[t[i]]%mod;su[t[i]]--;
		tr.add(t[i],-1);
		if(i==n&&n<m)as=(as+1)%mod;
	}
	printf("%d\n",as);
}
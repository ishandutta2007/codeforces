#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char cc[105];
int a[100005],d[10][100005],c[105][105];
long long sm[6][400005],lz[6][400005];
int powdv(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
void build(int K,int l,int r,int o)
{
	if(l==r)
	{
		sm[K][o]=1ll*a[l]*powdv(l,K)%mod;
		return;
	}
	int mid=l+r>>1;
	build(K,l,mid,o<<1);
	build(K,mid+1,r,o<<1|1);
	sm[K][o]=(sm[K][o<<1]+sm[K][o<<1|1])%mod;
}
void pushdown(int K,int l,int r,int o)
{
	if(lz[K][o]==-1)return;
	int mid=l+r>>1;
	sm[K][o<<1]=1ll*lz[K][o]*(d[K][mid]-d[K][l-1])%mod;
	sm[K][o<<1|1]=1ll*lz[K][o]*(d[K][r]-d[K][mid])%mod;
	lz[K][o<<1]=lz[K][o<<1|1]=lz[K][o],lz[K][o]=-1;
}
void add(int K,int l,int r,int o,int ll,int rr,int v)
{
	if(l>=ll&&r<=rr)
	{
		lz[K][o]=v;
		sm[K][o]=1ll*lz[K][o]*(d[K][r]-d[K][l-1])%mod;
		return;
	}
	pushdown(K,l,r,o);
	int mid=l+r>>1;
	if(mid>=ll)add(K,l,mid,o<<1,ll,rr,v);
	if(mid<rr)add(K,mid+1,r,o<<1|1,ll,rr,v);
	sm[K][o]=(sm[K][o<<1]+sm[K][o<<1|1])%mod;
}
int query(int K,int l,int r,int o,int ll,int rr)
{
	if(l>=ll&&r<=rr)return sm[K][o];
	pushdown(K,l,r,o);
	int mid=l+r>>1,ans=0;
	if(mid>=ll)ans+=query(K,l,mid,o<<1,ll,rr);
	if(mid<rr)ans+=query(K,mid+1,r,o<<1|1,ll,rr);
	return ans%mod;
}
int main()
{
	for(int i=0;i<=100;i++)c[i][0]=1;
	for(int i=1;i<=100;i++)for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(lz,-1,sizeof(lz));
	for(int K=0;K<=5;K++)
	{
		for(int i=1;i<=n;i++)d[K][i]=(d[K][i-1]+powdv(i,K))%mod;
		build(K,1,n,1);
	}
	while(m--)
	{
		scanf("%s",cc+1);
		if(cc[1]=='=')
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			for(int K=0;K<=5;K++)add(K,1,n,1,l,r,x);
		}else
		{
			int l,r,k,dd=0;
			scanf("%d%d%d",&l,&r,&k);
			for(int K=0;K<=k;K++)
			{
				int cs=1ll*powdv(1-l,k-K)*c[k][K]%mod;
				dd=(dd+1ll*cs*query(K,1,n,1,l,r))%mod;
			}
			printf("%d\n",(dd+mod)%mod);
		}
	}
	return 0;
}
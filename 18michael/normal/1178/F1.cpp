#include<cstdio>
#include<cstring>
#define LL long long
#define mod 998244353
int n,m;
int c[502];
LL f[502][502];
inline LL calc(int l,int r)
{
	if(l>r)return 1;
	if(~f[l][r])return f[l][r];
	int mn=l;LL res1=0,res2=0;
	for(int i=l+1;i<=r;++i)if(c[i]<c[mn])mn=i;
	for(int i=l;i<=mn;++i)res1=(res1+calc(l,i-1)*calc(i,mn-1))%mod;
	for(int i=mn;i<=r;++i)res2=(res2+calc(mn+1,i)*calc(i+1,r))%mod;
	return f[l][r]=(res1*res2)%mod;
}
int main()
{
	memset(f,-1,sizeof(f)),scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&c[i]);
	return 0&printf("%lld",calc(1,n));
}
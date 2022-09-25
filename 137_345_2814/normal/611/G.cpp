#include<cstdio>
using namespace std;
#define N 500050
#define mod 1000000007
long long s[N][2],su[N][3],tsz,as1;
int n;
struct node{int l,r,sz;long long s1,s2,s3,s4,s5,s6;}e[N*4];
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;e[x].sz=r-l+1;
	if(e[x].l==e[x].r){e[x].s1=e[x].s4=(mod-(1ll*s[l][0]*s[l==n?1:l+1][1]-1ll*s[l==n?1:l+1][0]*s[l][1])%mod)%mod;e[x].s2=e[x].s5=(mod+s[l][0]-s[l==n?1:l+1][0])%mod;e[x].s3=e[x].s6=(s[l==n?1:l+1][1]-s[l][1]+mod)%mod;return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	e[x].s1=(e[x<<1].s1+e[x<<1|1].s1)%mod;
	e[x].s2=(e[x<<1].s2+e[x<<1|1].s2)%mod;
	e[x].s3=(e[x<<1].s3+e[x<<1|1].s3)%mod;
	e[x].s4=(e[x<<1].s4+e[x<<1].s1*e[x<<1|1].sz+e[x<<1|1].s4)%mod;
	e[x].s5=(e[x<<1].s5+e[x<<1].s2*e[x<<1|1].sz+e[x<<1|1].s5)%mod;
	e[x].s6=(e[x<<1].s6+e[x<<1].s3*e[x<<1|1].sz+e[x<<1|1].s6)%mod;
}
int query(int x,int l,int r,int s1,int s2)
{
	if(l>r)return 0;
	if(e[x].l==l&&e[x].r==r)
	return (1ll*s2*e[x].s2+1ll*s1*e[x].s3+e[x].s1)%mod;
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return query(x<<1,l,r,s1,s2);
	else if(mid<l)return query(x<<1|1,l,r,s1,s2);
	else return (query(x<<1,l,mid,s1,s2)+query(x<<1|1,mid+1,r,s1,s2))%mod;
}
int query2(int x,int l,int r,int s1,int s2,int ct)
{
	if(l>r)return 0;
	if(e[x].l==l&&e[x].r==r)return (1ll*s2*e[x].s5+1ll*s1*e[x].s6+e[x].s4+1ll*(ct-1)*query(x,l,r,s1,s2))%mod;
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return query2(x<<1,l,r,s1,s2,ct);
	else if(mid<l)return query2(x<<1|1,l,r,s1,s2,ct);
	else return (query2(x<<1,l,mid,s1,s2,ct+r-mid)+query2(x<<1|1,mid+1,r,s1,s2,ct))%mod; 
}
long long doit(int x,int y)
{
	x^=y^=x^=y;
	if(y<1)return 0;
	if(x>y)return su[y][0]-(s[y==n?1:y+1][0]-s[1][0])*s[x][1]-(s[1][1]-s[y==n?1:y+1][1])*s[x][0];
	return su[y][0]-(s[y==n?1:y+1][0]-s[x==n?1:x+1][0])*s[x][1]-(s[x==n?1:x+1][1]-s[y==n?1:y+1][1])*s[x][0];
}
long long solve(int l,int r)
{
	if(l==r)return 0;
	if(r>l)return doit(r-1,l)-doit(l,l);
	else return doit(r-1,l)+doit(n,l)-doit(l,l);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&s[i][0],&s[i][1]);
		if(i>1)su[i-1][0]=su[i-2][0]+s[i][0]*s[i-1][1]-s[i-1][0]*s[i][1];
	}
	su[n][0]=su[n-1][0]+(s[1][0]*s[n][1]-s[n][0]*s[1][1]);
	for(int i=1;i<=n;i++)
	tsz+=s[i][0]*s[i==1?n:i-1][1]-s[i==1?n:i-1][0]*s[i][1];
	build(1,1,n);
	solve(7,3);
	for(int i=1;i<=n;i++)
	{
		int lb=i,rb=i+n-1,as=lb;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			if((unsigned long long)solve(i,(mid-1)%n+1)*2+(mid>n)<=tsz)as=mid,lb=mid+1;
			else rb=mid-1;
		}
		if(as<=n)as1=(as1+query2(1,i,as-1,(s[i][0]%mod+mod)%mod,(s[i][1]%mod+mod)%mod,1)+mod)%mod;
		else as1=(as1+query2(1,i,n,(s[i][0]%mod+mod)%mod,(s[i][1]%mod+mod)%mod,as-n)+query2(1,1,as-n-1,(s[i][0]%mod+mod)%mod,(s[i][1]%mod+mod)%mod,1))%mod;
	}
	as1=(1ll*n*(n-3)%mod*(mod+1)/2%mod*(tsz%mod)%mod-as1*2)%mod;
	printf("%d\n",(as1+mod)%mod);
}
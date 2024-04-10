#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define N 50050
int mod,n,m,ct,v[N];
struct mat{int s[2][2];};
mat operator*(mat a,mat b){return (mat){(1ll*a.s[0][0]*b.s[0][0]+1ll*a.s[0][1]*b.s[1][0])%mod,(1ll*a.s[0][0]*b.s[0][1]+1ll*a.s[0][1]*b.s[1][1])%mod,(1ll*a.s[1][0]*b.s[0][0]+1ll*a.s[1][1]*b.s[1][0])%mod,(1ll*a.s[1][0]*b.s[0][1]+1ll*a.s[1][1]*b.s[1][1])%mod};}
long long k,l[N*2],a,b;
map<long long,int> tp;
struct node{int l,r;mat su;}e[N*4];
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;
	if(l==r){e[x].su=(mat){v[l%n+1],1,v[l],0};return;}
	int mid=(e[x].l+e[x].r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	e[x].su=e[x<<1].su*e[x<<1|1].su;
}
mat query(int x,int l,int r)
{
	if(e[x].l==l&&e[x].r==r)return e[x].su;
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return query(x<<1,l,r);
	else if(mid<l)return query(x<<1|1,l,r);
	else return query(x<<1,l,mid)*query(x<<1|1,mid+1,r);
}
void mul(mat &a,mat &b)
{
	mat c;
	for(int i=0;i<=1;i++)for(int j=0;j<=1;j++)c.s[i][j]=0;
	for(int k=0;k<=1;k++)
	for(int i=0;i<=1;i++)
	if(a.s[i][k])
	for(int j=0;j<=1;j++)
	c.s[i][j]=(c.s[i][j]+1ll*a.s[i][k]*b.s[k][j])%mod;
	a=c;
}
mat pw(mat a,long long p)
{
	mat b;
	for(int i=0;i<=1;i++)for(int j=0;j<=1;j++)b.s[i][j]=(i==j);
	while(p){if(p&1)mul(b,a);mul(a,a);p>>=1;}
	return b;
}
mat query(long long l,long long r)
{
	if(l>r)return (mat){1,0,0,1};
	if((l-1)%n<=(r-1)%n&&r-l==(r-1)%n-(l-1)%n)
	return query(1,(l-1)%n+1,(r-1)%n+1);
	else
	{
		long long ln=(l-1)/n*n+n,rn=(r-1)/n*n;
		return query(1,(l-1)%n+1,n)*pw(query(1,1,n),(rn-ln)/n)*query(1,1,(r-1)%n+1);
	}
}
int main()
{
	scanf("%lld%d",&k,&mod);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%lld%lld",&a,&b);
		l[++ct]=a+1;l[++ct]=a+2;
		tp[a]=(int)b;
	}
	if(k<2){printf("%d\n",k%mod);return 0;}
	sort(l+1,l+ct+1);
	int s1=0,s2=1;
	long long las=1;
	l[0]=1;
	for(int i=1;i<=ct;i++)if(l[i]!=l[i-1])
	{
		if(l[i]>k)
		{
			mat tp=query(las,k-1);
			printf("%d\n",(1ll*s1*tp.s[1][0]+1ll*s2*tp.s[0][0])%mod);
			return 0;
		}
		else
		{
			if(l[i]>las+1)
			{
				mat tp=query(las,l[i]-2);
				int t=(1ll*s1*tp.s[1][1]+1ll*s2*tp.s[0][1])%mod;
				s2=(1ll*s1*tp.s[1][0]+1ll*s2*tp.s[0][0])%mod;
				s1=t;
			}
			int l1=v[(l[i]-2)%n+1],l2=v[(l[i]-1)%n+1];
			if(tp.count(l[i]-2))l1=tp[l[i]-2];
			if(tp.count(l[i]-1))l2=tp[l[i]-1];
			int s=(1ll*s2*l2+1ll*l1*s1)%mod;
			s1=s2;s2=s;
		}
		las=l[i];
	}
	mat tp=query(las,k-1);
	printf("%d\n",(1ll*s1*tp.s[1][0]+1ll*s2*tp.s[0][0])%mod);
	return 0;
}
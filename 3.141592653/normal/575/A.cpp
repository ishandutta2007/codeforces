#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
ll n,k,m,p;
struct matrix
{ll a,b,c,d;matrix(ll x=1,ll y=0,ll z=0,ll w=1){a=x,b=y,c=z,d=w;}};
matrix operator*(matrix x,matrix y)
{retrun matrix((x.a*y.a+x.c*y.b)%p,(x.b*y.a+x.d*y.b)%p,(x.a*y.c+x.c*y.d)%p,(x.b*y.c+x.d*y.d)%p);}
matrix seg[555555];
matrix pref[111111],rm[111111];
void precalc(int l=1,int r=n,int p=1)
{
	if(l==r){seg[p]=rm[l];return;}
	int mid=(l+r)>>1;
	precalc(l,mid,p<<1),precalc(mid+1,r,p<<1|1),seg[p]=seg[p<<1]*seg[p<<1|1];
}
matrix query(int l,int r,int p=1,int pl=1,int pr=n)
{
	if(l>pr||pl>r)return matrix();
	if(l<=pl&&pr<=r)return seg[p];
	int mid=(pl+pr)>>1;
	return query(l,r,p<<1,pl,mid)*query(l,r,p<<1|1,mid+1,pr);
}
struct pii
{ll x,w,op;}pi[111111];
bool operator<(cpnst pii x,cpnst pii y)
{return x.x<y.x;}
#include<map>
std::map<ll,int>g;
#include<vector>
std::vector<pii>v[111111];
ll stk[111111],top,s[111111];
void insert(ll x,ll w,int op)
{
	int uni=(x-1)%n+1;
	((x-=1)/=n)++;
	if(stk[top]!=x)stk[++top]=x;
	v[top].push_back(pii{uni,w,op});
}matrix pow(matrix x,ll k)
{matrix r=matrix();for(;k;k>>=1,x=x*x)if(k&1)r=r*x;return r;}
matrix extend(int pos)
{
	register int i;
	matrix r=matrix();
	int nw=0;
	for(i=0;i<v[pos].size();i++)
	{
		if(i+1<v[pos].size()&&v[pos][i].x==v[pos][i+1].x)continue;
		r=r*query(nw+1,v[pos][i].x-1);
		matrix tr=matrix(s[v[pos][i].x%n],s[v[pos][i].x-1],1,0);
		((v[pos][i].op)?tr.b:tr.a)=v[pos][i].w;
		if(i&&v[pos][i].x==v[pos][i-1].x)
			tr=matrix(v[pos][i].w,v[pos][i-1].w,1,0);
		r=r*tr,nw=v[pos][i].x;
	}r=r*query(nw+1,n);
	return r;
}
matrix prefix(int pos,int res)
{
	register int i;
	matrix r=matrix();
	for(auto tp:v[pos])
		(tp.op?rm[tp.x%n].b:rm[tp.x%n].a)=tp.w;
	for(i=1;i<=res;i++)r=r*rm[i];
	return r;
}
matrix split(ll enl,ll rem)
{
	register int i;
	if(!rem)return matrix();
	for(i=1;i<=top;i++)if(stk[i]==enl)return prefix(i,rem);
	return query(1,rem);
} 
void solve()
{
	register int i;
	for(i=1;i<=m;i++)
		insert(pi[i].x,pi[i].w,0),insert(pi[i].x+1,pi[i].w,1);
	matrix ans(1,0,0,0);
	ll trans=k-1,rng=trans/n,nw=0;
	for(i=1;i<=top;i++)
	{
		if(stk[i]>rng)break;
		ll tt=stk[i]-nw-1;
		if(tt>0)ans=ans*pow(pref[n],tt);
		ans=ans*extend(i),nw=stk[i];
	}ans=ans*pow(pref[n],rng-nw)*split(rng+1,trans%n);
	printf("%lld\n",ans.a%p);
}
ll r[111111],d[111111];
#include<algorithm>
int main()
{
	scanf("%lld%lld%lld",&k,&p,&n);
	if(k<2)return printf("%lld\n",k%p),0;
	register int i;
	for(i=0;i<n;i++)
		scanf("%lld",s+i);
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
		scanf("%lld%lld",&pi[i].x,&pi[i].w);
	std::sort(pi+1,pi+m+1);
	for(pref[0]=matrix(),i=1;i<=n;i++)
		pref[i]=pref[i-1]*(rm[i]=matrix(s[i%n],s[i-1],1,0));
	precalc(),solve();
}
/*
Just go for it.
*/
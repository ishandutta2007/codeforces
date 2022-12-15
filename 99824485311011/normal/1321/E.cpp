#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,m,p;
ll mncstx[400010],mncsty[400010];
ll mx[1600010],tag[1600010];
vector<int> lsx,lsy;
pair<int,int> A[200010],B[200010];
int x[200010],y[200010],z[200010];
void pushnow(int p,ll v)
{
	tag[p]+=v;
	mx[p]+=v;
}
void pushdown(int p)
{
	if(tag[p])
	{
		pushnow(lc,tag[p]);
		pushnow(rc,tag[p]);
		tag[p]=0;
	}
}
void modify(int p,int l,int r,int ml,int mr,int v)
{
	if(ml<=l&&r<=mr)
	{
		pushnow(p,v);
		return;
	}
	pushdown(p);
	int mid=(l+r)>>1;
	if(ml<=mid)modify(lc,l,mid,ml,mr,v);
	if(mr>mid)modify(rc,mid+1,r,ml,mr,v);
	mx[p]=max(mx[lc],mx[rc]);
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		mx[p]=-mncsty[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	mx[p]=max(mx[lc],mx[rc]);
}
vector<pair<int,int> > v[400010];
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	memset(mncstx,0x2f,sizeof(mncstx));
	memset(mncsty,0x2f,sizeof(mncsty));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&A[i].first,&A[i].second);
		A[i].first--;
		lsx.push_back(A[i].first);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&B[i].first,&B[i].second);
		B[i].first--;
		lsy.push_back(B[i].first);
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		lsx.push_back(x[i]);
		lsy.push_back(y[i]);
	}
	sort(lsx.begin(),lsx.end());sort(lsy.begin(),lsy.end());
	lsx.erase(unique(lsx.begin(),lsx.end()),lsx.end()),lsy.erase(unique(lsy.begin(),lsy.end()),lsy.end());
	for(int i=1;i<=n;i++)
	{
		int p=lower_bound(lsx.begin(),lsx.end(),A[i].first)-lsx.begin();
		mncstx[p]=min(mncstx[p],(ll)A[i].second);
	}
	for(int i=1;i<=m;i++)
	{
		int p=lower_bound(lsy.begin(),lsy.end(),B[i].first)-lsy.begin();
		mncsty[p]=min(mncsty[p],(ll)B[i].second);
	}
	for(int i=1;i<=p;i++)
		v[lower_bound(lsx.begin(),lsx.end(),x[i])-lsx.begin()].push_back(make_pair(lower_bound(lsy.begin(),lsy.end(),y[i])-lsy.begin(),z[i]));
	ll ans=-1e18;
	build(1,0,lsy.size()-1);
	for(int i=0;i<lsx.size();i++)
	{
		for(auto &x:v[i])modify(1,0,lsy.size()-1,x.first,lsy.size()-1,x.second);
		ans=max(ans,mx[1]-mncstx[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
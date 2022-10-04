#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef set<int>::iterator iter;
const int MAXN=100005;

int n,m,a[MAXN];
set<int> s[MAXN];
inline int getpre(int x,int u)
	{iter it=s[u].lower_bound(x);--it;return *it;}
inline int getnxt(int x,int u)
	{return *s[u].upper_bound(x);}
ll ans[MAXN];

int cnt=0;
struct Data //A works on B <=> A.l>=B.l && A.r<=B.r && A.x<=B.x
{
	int op,l,r,x,val,id;
	Data(){}
	Data(int op,int l,int r,int x,int val,int id):
		op(op),l(l),r(r),x(x),val(val),id(id){}
	inline bool operator <(const Data &b)const{return x<b.x;}
}d[MAXN*7];
inline bool cmp(Data a,Data b){return a.l!=b.l?a.l>b.l:a.op>b.op;}

ll c[MAXN];
void add(int x,int y){for(;x<=n;x+=(x&-x))c[x]+=y;}
ll query(int x){ll s=0;for(;x;x-=(x&-x))s+=c[x];return s;}
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	sort(d+l,d+r+1,cmp);
	for(int i=l;i<=r;i++)
		if(d[i].id<=mid && d[i].op==2)add(d[i].r,d[i].val);
		else if(d[i].id>mid && d[i].op==1)ans[d[i].val]+=query(d[i].r);
	for(int i=l;i<=r;i++)
		if(d[i].id<=mid && d[i].op==2)add(d[i].r,-d[i].val);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int op,u,v,qid=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)s[i].insert(0),s[i].insert(n+1);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		u=getnxt(i,a[i]);
		if(u<=n)d[++cnt]=Data(2,i,u,0,u-i,cnt);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&u,&v);
		if(op==2)d[++cnt]=Data(1,u,v,i,++qid,cnt);
		else
		{
			int x=getpre(u,a[u]),y=getnxt(u,a[u]);
			if(x)d[++cnt]=Data(2,x,u,i,x-u,cnt);
			if(y<=n)d[++cnt]=Data(2,u,y,i,u-y,cnt);
			if(x && y<=n)d[++cnt]=Data(2,x,y,i,y-x,cnt);
			s[a[u]].erase(u);
			a[u]=v;
			s[a[u]].insert(u);
			x=getpre(u,a[u]),y=getnxt(u,a[u]);
			if(x)d[++cnt]=Data(2,x,u,i,u-x,cnt);
			if(y<=n)d[++cnt]=Data(2,u,y,i,y-u,cnt);
			if(x && y<=n)d[++cnt]=Data(2,x,y,i,x-y,cnt);
		}
	}
	solve(1,cnt);
	for(int i=1;i<=qid;i++)
		printf("%lld\n",ans[i]);
    return 0;
}
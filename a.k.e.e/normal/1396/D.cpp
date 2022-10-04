#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=2005;
typedef multiset<int>::iterator iter;

int n,k,L;
pair<pii,int> a[MAXN];
int mx,px[MAXN],my,py[MAXN];
multiset<int> cp[MAXN];

int sum[MAXN<<2],fir[MAXN<<2],sec[MAXN<<2],d[MAXN<<2],tag[MAXN<<2];
void update(int id)
{
	if(fir[id<<1]==fir[id<<1|1])
	{
		fir[id]=fir[id<<1];
		sec[id]=min(sec[id<<1],sec[id<<1|1]);
		d[id]=d[id<<1]+d[id<<1|1];
	}
	else if(fir[id<<1]<fir[id<<1|1])
	{
		fir[id]=fir[id<<1];
		sec[id]=min(sec[id<<1],fir[id<<1|1]);
		d[id]=d[id<<1];
	}
	else
	{
		fir[id]=fir[id<<1|1];
		sec[id]=min(fir[id<<1],sec[id<<1|1]);
		d[id]=d[id<<1|1];
	}
	sum[id]=dmy(sum[id<<1]+sum[id<<1|1]);
}
void pushdown(int id)
{
	if(!tag[id])return;
	if(tag[id]>fir[id<<1|1])inc(sum[id<<1|1],1ll*(py[fir[id<<1|1]]-py[tag[id]]+MOD)*d[id<<1|1]%MOD),fir[id<<1|1]=tag[id<<1|1]=tag[id];
	if(tag[id]>fir[id<<1])inc(sum[id<<1],1ll*(py[fir[id<<1]]-py[tag[id]]+MOD)*d[id<<1]%MOD),fir[id<<1]=tag[id<<1]=tag[id];
	tag[id]=0;
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(ql>qr)return;
	if(c<=fir[id])return;
	if(l==ql && r==qr && c<sec[id])
	{
		inc(sum[id],1ll*(py[fir[id]]-py[c]+MOD)*d[id]%MOD);
		fir[id]=tag[id]=c;
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}
void build(int id,int l,int r)
{
	tag[id]=0;
	if(l==r)
	{
		d[id]=py[l]-py[l-1];
		fir[id]=l;sec[id]=1<<30;
		sum[id]=1ll*(py[l]-py[l-1])*(L-py[l]+1)%MOD;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}
/*void debug(int id,int l,int r)
{
	cerr<<id<<" "<<l<<" "<<r<<" : "<<fir[id]<<" "<<sec[id]<<endl;
	if(l==r)return;
	pushdown(id);
	int mid=(l+r)>>1;
	debug(id<<1,l,mid);
	debug(id<<1|1,mid+1,r);
}*/

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(k),readint(L);
	for(int i=1;i<=n;++i)readint(a[i].x.x),readint(a[i].x.y),readint(a[i].y),px[i]=++a[i].x.x,py[i]=++a[i].x.y;
	sort(px+1,px+n+1),mx=unique(px+1,px+n+1)-px-1;px[mx+1]=L+1;
	sort(py+1,py+n+1),my=unique(py+1,py+n+1)-py-1;py[my+1]=L+1;
	for(int i=1;i<=n;++i)a[i].x.x=lower_bound(px+1,px+mx+1,a[i].x.x)-px,a[i].x.y=lower_bound(py+1,py+my+1,a[i].x.y)-py;
	sort(a+1,a+n+1);a[n+1].x=mp(mx+1,my+1);
	
	int ans=0;
	for(int i=1;i<=mx;++i)
	{
		build(1,1,my+1);
		for(int j=1;j<=k;++j)cp[j].clear();
		for(int j=1;j<=n && a[j].x.x<=i;++j)cp[a[j].y].insert(a[j].x.y);
		for(int j=1;j<=k;++j)
		{
			int las=0;
			cp[j].insert(my+1);
			for(auto t:cp[j])modify(1,1,my+1,las+1,t,t),las=t;
			cp[j].insert(0);
		}
		inc(ans,1ll*px[a[1].x.x]*sum[1]%MOD*(px[i+1]-px[i])%MOD);
//debug(1,1,my+1);cerr<<endl;
		for(int j=1;j<=n && a[j].x.x<i;++j)
		{
			int c=a[j].y,y=a[j].x.y;
			iter it=cp[c].find(y);
			int u=*(--it);++it;int v=*(++it);--it;
			cp[c].erase(it);
//cerr<<u<<" "<<y<<" "<<v<<endl;
			modify(1,1,my+1,u+1,y,v);
//debug(1,1,my+1);cerr<<endl;
			inc(ans,1ll*(px[a[j+1].x.x]-px[a[j].x.x])*sum[1]%MOD*(px[i+1]-px[i])%MOD);
		}
	}
	printf("%d\n",ans);
	return 0;
}
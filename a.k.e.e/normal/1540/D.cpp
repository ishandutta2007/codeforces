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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=100005,B=500;

int n,b[MAXN];
vector<int> f[MAXN<<2];
void update(int id)
{
	int u=id<<1,v=id<<1|1;f[id].clear();
	for(int i=0,j=0;i<f[u].size() || j<f[v].size();)
	{
		if(j==f[v].size() || (i<f[u].size() && f[u][i]<f[v][j]-i) )f[id].pb(f[u][i++]);
		else f[id].pb(f[v][j++]-i);
	}
}
void build(int id,int l,int r)
{
	if(l==r){f[id].pb(b[l]);return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	if(r-l+1<=B)update(id);
}
int query(int id,int l,int r,int ql,int qr,int x)
{
	if(l==ql && r==qr && r-l+1<=B)return x+upper_bound(f[id].begin(),f[id].end(),x)-f[id].begin();
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr,x);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr,x);
	x=query(id<<1,l,mid,ql,mid,x);
	return query(id<<1|1,mid+1,r,mid+1,qr,x);
}
void modify(int id,int l,int r,int x,int c)
{
	if(l==r){f[id][0]=c;return;}
	int mid=(l+r)>>1;
	x<=mid?modify(id<<1,l,mid,x,c):modify(id<<1|1,mid+1,r,x,c);
	if(r-l+1<=B)update(id);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(b[i]),b[i]=i-b[i];
	build(1,1,n);
	int Q;readint(Q);
	while(Q--)
	{
		int op,x,y;readint(op),readint(x);
		if(op==1)
		{
			readint(y);y=x-y;
			b[x]=y;
			modify(1,1,n,x,y);
		}
		else printf("%d\n",x==n?b[n]:query(1,1,n,x+1,n,b[x]));
	}
	return 0;
}
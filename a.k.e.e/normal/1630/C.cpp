#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=200005;
const int INF=0x3f3f3f3f;

int n;
int a[MAXN],f[MAXN];
int Max[MAXN<<2],tag[MAXN<<2];
void pushdown(int id)
{
	Max[id<<1]+=tag[id],tag[id<<1]+=tag[id];
	Max[id<<1|1]+=tag[id],tag[id<<1|1]+=tag[id];
	tag[id]=0;
}
void update(int id){Max[id]=max(Max[id<<1],Max[id<<1|1]);}
void make(int id,int l,int r,int x,int c)
{
	if(l==r){chkmax(Max[id],c);return;}
	pushdown(id);
	int mid=(l+r)>>1;
	x<=mid?make(id<<1,l,mid,x,c):make(id<<1|1,mid+1,r,x,c);
	update(id);
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql&&r==qr){Max[id]+=c,tag[id]+=c;return;}
	pushdown(id);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(id<<1,l,mid,ql,min(qr,mid),c);
	if(qr>mid)modify(id<<1|1,mid+1,r,max(ql,mid+1),qr,c);
	update(id);
}
int qmax(int id,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return Max[id];
	pushdown(id);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)chkmax(res,qmax(id<<1,l,mid,ql,min(qr,mid)) );
	if(qr>mid)chkmax(res,qmax(id<<1|1,mid+1,r,max(ql,mid+1),qr) );
	return res;
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),chkmax(f[a[i]],i);
	memset(Max,-0x3f,sizeof(Max));
	make(1,0,n,0,0);
	for(int i=1;i<=n;++i)
	{
		int val=qmax(1,0,n,0,f[a[i]]);
		if(i<n)modify(1,0,n,i+1,n,1);
		make(1,0,n,f[a[i]],val);
	}
	printf("%d\n",Max[1]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
//	readint(T);
	T=1;
	while(T--)solve();
	return 0;
}
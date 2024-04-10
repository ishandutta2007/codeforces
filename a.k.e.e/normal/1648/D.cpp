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
const int MAXN=2000005;
const ll INF=0x3f3f3f3f3f3f3f3fll;

int n,q,m;
int a[3][MAXN],w[MAXN];
ll pre[MAXN],suf[MAXN],res=INF;
int lf[MAXN],ch[MAXN][2],rt;
vector<int> al[MAXN],wr[MAXN];
ll go[MAXN];
ll dis[MAXN];
int build(int l,int r)
{
	if(l==r)return lf[l]=++m;
	int u=++m,mid=(l+r)>>1;
	ch[u][0]=build(l,mid);
	ch[u][1]=build(mid+1,r);
	return u;
}
void work(int id,int l,int r,int ql,int qr,int u)
{
	if(l==ql&&r==qr){al[u].pb(id);chkmin(go[id],(ll)w[u]);return;}
	int mid=(l+r)>>1;
	chkmin(go[ch[id][0]],go[id]);
	chkmin(go[ch[id][1]],go[id]);
	if(qr<=mid)return work(ch[id][0],l,mid,ql,qr,u);
	if(ql>mid)return work(ch[id][1],mid+1,r,ql,qr,u);
	work(ch[id][0],l,mid,ql,mid,u);
	work(ch[id][1],mid+1,r,mid+1,qr,u);
}
void solve(int id,int l,int r)
{
	if(l==r)
	{
		chkmin(res,dis[id+m]-suf[l+1]);
		chkmin(dis[id],dis[id+m]);
		chkmin(dis[id],-pre[l]);
		for(auto i:wr[id])
			for(auto j:al[i])
				if(j>id)chkmin(dis[j+m],dis[id]+w[i]);
		return;
	}
	chkmin(go[ch[id][0]],go[id]);
	chkmin(go[ch[id][1]],go[id]);
	int mid=(l+r)>>1;
	chkmin(dis[ch[id][0]+m],dis[id+m]);
	chkmin(dis[ch[id][1]+m],dis[id+m]);
	solve(ch[id][0],l,mid);
	chkmin(dis[ch[id][1]+m],dis[ch[id][0]]+go[id]);
	solve(ch[id][1],mid+1,r);
	chkmin(dis[id],dis[ch[id][0]]);
	chkmin(dis[id],dis[ch[id][1]]);
	for(auto i:wr[id])
		for(auto j:al[i])
			if(j>id)chkmin(dis[j+m],dis[id]+w[i]);
}
void solve()
{
	readint(n),readint(q);
	for(int k=0;k<3;++k)
		for(int i=1;i<=n;++i)
			readint(a[k][i]);
	for(int i=0;i<n;++i)pre[i]=pre[i-1]+a[0][i+1]-a[1][i];
	for(int i=n+1;i>=2;--i)suf[i]=suf[i+1]+a[2][i-1]-a[1][i];
	memset(dis,0x3f,sizeof(dis));
	memset(go,0x3f,sizeof(go));
	rt=build(0,n);
	for(int i=1;i<=q;++i)
	{
		int l,r;
		readint(l),readint(r),readint(w[i]);
		work(rt,0,n,l-1,r,i);
		for(auto j:al[i])wr[j].pb(i);
	}
	solve(rt,0,n);
	res=-res;
	for(int i=1;i<=n;++i)res+=a[1][i];
	printf("%lld\n",res);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	T=1;
	while(T--)solve();
	return 0;
}
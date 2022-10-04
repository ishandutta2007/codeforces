#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll> pil;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=1600005;
mt19937 mt(10032);
int n,root;
pii a[MAXN];
int len[MAXN],sum[MAXN],sz[MAXN];
int ch[MAXN][2],rd[MAXN],stot;
int newnode(int x)
{
	int u=++stot;
	len[u]=sum[u]=x,sz[u]=1;
	ch[u][0]=ch[u][1]=0;rd[u]=mt();
	return u;
}
void update(int u)
{
	sz[u]=1;sum[u]=len[u];
	for(int i=0;i<=1;++i)sz[u]+=sz[ch[u][i]],sum[u]+=sum[ch[u][i]];
}
void split(int u,int w,int &x,int &y)//<=w; >w
{
	if(!u){x=y=0;return;}
	if(w<=sz[ch[u][0]])
	{
		split(ch[u][0],w,x,y);
		ch[u][0]=y;
		update(u);
		y=u;
		return;
	}
	split(ch[u][1],w-sz[ch[u][0]]-1,x,y);
	ch[u][1]=x;
	update(u);
	x=u;
}
int merge(int u,int v)
{
	if(!u || !v)return u|v;
	if(rd[u]<rd[v]){ch[u][1]=merge(ch[u][1],v);update(u);return u;}
	ch[v][0]=merge(u,ch[v][0]);update(v);return v;
}
int find(int u,int e)
{
	if(!u)return 1;
	if(e<=sum[ch[u][0]])return find(ch[u][0],e);
	if(e<=sum[ch[u][0]]+len[u])return sz[ch[u][0]]+1;
	return sz[ch[u][0]]+1+find(ch[u][1],e-sum[ch[u][0]]-len[u]);
}
ll final(int u)
{
	if(!u)return 0;
	ll res=final(ch[u][1]);
	res+=1ll*(sz[ch[u][1]]+1)*(len[u]+sum[ch[u][0]]);
	res+=final(ch[u][0]);
	return res;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	ll ad=0;

	readint(n);
	for(int i=1;i<=n;++i)readint(a[i].x),readint(a[i].y),a[i].x+=a[i].y;
	sort(a+1,a+n+1);
	root=newnode(0);
	for(int i=1;i<=n;++i)
	{
		int dx=a[i].x-a[i-1].x,ey=a[i].y;
		ad+=ey;
		int x,y,z;
		split(root,i-1,x,y);
		split(y,1,y,z);
		len[y]+=dx;sum[y]+=dx;
		root=merge(merge(x,y),z);
		int p=find(root,ey);
		split(root,p-1,x,y);
		split(y,1,y,z);
		int vl=ey-sum[x],vr=len[y]-vl;
		len[y]=sum[y]=0;
		root=merge(merge(x,merge(merge(newnode(vl),y),newnode(vr)) ),z);
	}

	int x,y;
	split(root,n,x,y);
	printf("%lld\n",ad-final(x));
	return 0;
}
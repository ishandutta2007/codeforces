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
const int MAXN=1100005,INF=0x3f3f3f3f;

int k,res[MAXN],cur;
bool hv[MAXN];
int ch[MAXN<<2][2],vl[MAXN<<2],vr[MAXN<<2],md[MAXN<<2];
void update(int id,int l,int r)
{
	int len=(r-l+1)/2;
	vl[id]=INF,vr[id]=-INF,md[id]=vl[ch[id][1]]+len-vr[ch[id][0]];
	for(int i=0;i<2;++i)
		chkmin(vl[id],vl[ch[id][i]]+i*len),
		chkmax(vr[id],vr[ch[id][i]]+i*len),
		chkmin(md[id],md[ch[id][i]]);
}
void build(int id,int l,int r)
{
	if(l==r)
	{
		if(hv[l])vl[id]=vr[id]=0;
		else vl[id]=INF,vr[id]=-INF;
		md[id]=INF;
		return;
	}
	int mid=(l+r)>>1;
	build(ch[id][0]=id<<1,l,mid);
	build(ch[id][1]=id<<1|1,mid+1,r);
	update(id,l,r);
}
void exchg(int id,int l,int r,int c)
{
	if(r-l+1==(1<<c))return;
	int mid=(l+r)>>1;
	if(r-l+1==(1<<c+1))swap(ch[id][0],ch[id][1]);
	exchg(ch[id][0],l,mid,c);
	exchg(ch[id][1],mid+1,r,c);
	update(id,l,r);
}
void work(int u)
{
	if(u==k)return;
	work(u+1);
	exchg(1,0,(1<<k)-1,u);
	cur^=(1<<u);
	res[cur]=md[1];
	work(u+1);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int N;
	readint(N),readint(k);
	while(N--)
	{
		int u;readint(u);
		hv[u]=1;
	}
	build(1,0,(1<<k)-1);
	res[0]=md[1];
	work(0);
	for(int i=0;i<(1<<k);++i)printf("%d ",res[i]);
	return 0;
}
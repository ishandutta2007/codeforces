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
/*const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=200005;

int n,a[MAXN],b[MAXN];
vector<int> G[MAXN];
vector<pii> res;
bool vis[MAXN];
void calc(int x,int y)
{
	res.pb(mp(a[x],a[y]));
	swap(a[x],a[y]);
}
void work(vector<int> x,vector<int> y)
{
	calc(x.back(),y.back());
	for(int i=x.size()-1;i;--i)calc(x[i],x[i-1]);
	for(int i=y.size()-1;i;--i)calc(y[i],y[i-1]);
	calc(x[0],y[0]);
}
void solve(vector<int> x)
{
	if(x.size()==2)
	{
		int y;
		for(int i=1;i<=n;++i)
			if(i!=x[0] && i!=x[1])
				{y=i;break;}
		calc(x[0],y);
		calc(x[0],x[1]);
		calc(x[1],y);
	}
	else
	{
		calc(x[x.size()-1],x[0]);
		calc(x[0],x[1]);
		swap(x[0],x[1]);
		for(int i=x.size()-1;i;--i)calc(x[i],x[i-1]);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(b[i]);
	for(int i=1;i<=n;++i)a[b[i]]=i;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==i)vis[i]=1;
		if(vis[i])continue;
		G[i].pb(i);
		for(int x=a[i];x!=i;x=a[x])vis[x]=1,G[i].pb(x);
	}
	int las=0;
	for(int i=1;i<=n;++i)
	{
		if(G[i].empty())continue;
		if(!las)las=i;
		else work(G[i],G[las]),las=0;
	}
	if(las)solve(G[las]);
	printf("%d\n",res.size());
	for(auto p:res)printf("%d %d\n",p.x,p.y);
	return 0;
}
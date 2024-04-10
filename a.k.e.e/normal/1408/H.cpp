#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=500005;

int n,a[MAXN];
vector<int> b[MAXN],bl,br,d[MAXN];
pii c[MAXN];
int e[MAXN];
void solve()
{
	readint(n);
	for(int i=0;i<=n;++i)b[i].clear(),d[i].clear();
	for(int i=1;i<=n;++i)b[i].pb(0);
	for(int i=1;i<=n;++i)readint(a[i]),b[a[i]].pb(i);
	for(int i=1;i<=n;++i)b[i].pb(n+1);
	if(b[0].size()<2){printf("0\n");return;}
	int z=b[0].size()-1;
	int R=z/2+1,L=(z+1)/2-1;
	bl.clear(),br.clear();
	for(int i=0;i<=L;++i)bl.pb(b[0][i]);
	for(int i=R;i<=z;++i)br.pb(b[0][i]);
	z=bl.size();
	for(int i=1;i<=n;++i)
	{
		if(b[i].size()==2)continue;
		int u=*(lower_bound(b[i].begin(),b[i].end(),br[0])-1),
			v=*upper_bound(b[i].begin(),b[i].end(),bl[z-1]);
		int p=lower_bound(bl.begin(),bl.end(),u)-bl.begin(),
			q=z-(lower_bound(br.begin(),br.end(),v)-br.begin());
		d[p].pb(q);
//cerr<<p<<" "<<q<<endl;
	}
	int res=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=z;i>=0;--i)
	{
		for(auto j:d[i])pq.push(j);
		if(pq.empty())continue;
		if(i)++res,pq.pop();
	}
	memset(e,0,sizeof(int)*(z+1));
	while(!pq.empty())++e[pq.top()],pq.pop();
	for(int i=z,cur=0;i;--i)
	{
		cur+=e[i];
		if(cur)--cur,++res;
	}
	printf("%d\n",min(res,z));
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}
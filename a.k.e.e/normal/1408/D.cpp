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
const int MAXN=2005,k=1000002,MAXK=1000015;

int n,m;
pii a[MAXN],b[MAXN];
vector<pii> c[MAXK];
int cnt[MAXK],cur=0;

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=n;++i)readint(a[i].x),readint(a[i].y);
	for(int i=1;i<=m;++i)readint(b[i].x),readint(b[i].y);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i].x<=b[j].x && a[i].y<=b[j].y)
				++cnt[b[j].y-a[i].y+1],
				c[b[j].x-a[i].x+1].pb(mp(i,j));
	++cnt[0];
	cur=k;
	while(!cnt[cur])--cur;
	int ans=cur;
	for(int d=1;d<=k;++d)
	{
		for(auto p:c[d])
		{
			int i=p.x,j=p.y;
			--cnt[b[j].y-a[i].y+1];
			while(!cnt[cur])--cur;
		}
		chkmin(ans,d+cur);
	}
	printf("%d\n",ans);
	return 0;
}
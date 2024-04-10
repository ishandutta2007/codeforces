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
const int MAXN=105;

pii a[3];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int L=1<<30,R=-1<<30;
	for(int i=0;i<3;++i)readint(a[i].x),readint(a[i].y),chkmin(L,a[i].y),chkmax(R,a[i].y);
	sort(a,a+3);
	vector<pair<pii,pii> > v;
	v.pb(mp(mp(a[1].x,L),mp(a[1].x,R)) );
	v.pb(mp(a[0],mp(a[1].x,a[0].y)) );
	v.pb(mp(a[2],mp(a[1].x,a[2].y)) );
	vector<pair<pii,pii> > g;
	for(auto p:v)if(p.x!=p.y)g.pb(p);
	printf("%d\n",g.size());
	for(auto p:g)printf("%d %d %d %d\n",p.x.x,p.x.y,p.y.x,p.y.y);
	return 0;
}
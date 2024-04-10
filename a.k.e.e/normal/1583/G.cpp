#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
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
const int MAXN=400005;

int n;
pii a[MAXN];
bool os[MAXN];
int perm[MAXN],c[MAXN];
vector<int> al;
void add(int u,int d){for(;u<=2*n;u+=(u&-u))inc(c[u],d);}
int query(int u){int x=0;for(;u;u-=(u&-u))inc(x,c[u]);return x;}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i].x),readint(a[i].y),perm[i]=i;
	int T;readint(T);
	for(int s;T--;)readint(s),os[s]=1;
	sort(perm+1,perm+n+1,[&](int p,int q){return a[p].y<a[q].y;});
	for(int ii=n;ii;--ii)
	{
		int i=perm[ii];
		if(os[i] && (al.empty() || a[i].x>a[al.back()].x) )al.pb(i);
	}
	reverse(al.begin(),al.end());
	int u=0,res=0;
	for(int ii=1;ii<=n;++ii)
	{
		int i=perm[ii],k=dmy(dmy(MOD+query(2*n)-query(a[i].x)+1));
		add(a[i].x,k);
		if(u<al.size() && al[u]==i)++u,inc(res,dmy(query(a[i].x)-(u<al.size()?query(a[al[u]].x-1):0)+MOD));
	}
	printf("%d\n",res);
	return 0;
}
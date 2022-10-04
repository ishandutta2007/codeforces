#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=500005;

struct Hash
{
	static const int MOD1=998244353,MOD2=1000000007,MOD3=1019260817;
	int x,y,z;
	Hash(){}
	Hash(int x,int y,int z):x(x%MOD1),y(y%MOD2),z(z%MOD3){}
	Hash operator +(const Hash &b)const{return Hash(x+b.x,y+b.y,z+b.z);}
	bool operator <(const Hash &b)const
	{
		if(x!=b.x)return x<b.x;
		if(y!=b.y)return y<b.y;
		return z<b.z;
	}
	bool operator !=(const Hash &b)const{return x!=b.x || y!=b.y || z!=b.z;}
}pw[MAXN];

int n;
ll a[MAXN];
pair<Hash,int> pr[MAXN];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void solve()
{
	int E,u,v;
	readint(n),readint(E);
	for(int i=1;i<=n;++i)readint(a[i]),pr[i].y=i;
	pw[0]=Hash(1,1,1);
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]+pw[i-1],pr[i].x=Hash(0,0,0);
	while(E--)
	{
		readint(u),readint(v);
		pr[v].x=pr[v].x+pw[u];
	}
	sort(pr+1,pr+n+1);
	ll ans=0,sum=0;
	for(int i=1;i<=n;++i)
		if(pr[i].x!=pr[i-1].x)
		{
			if(pr[i-1].x!=Hash(0,0,0))ans=gcd(ans,sum);
			sum=a[pr[i].y];
		}
		else sum+=a[pr[i].y];
	ans=gcd(ans,sum);
	cout<<ans<<'\n';
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}
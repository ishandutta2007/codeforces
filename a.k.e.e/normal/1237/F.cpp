#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=3605,MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}

int n,m,Q,ns,ms,nc,mc;
bool visx[MAXN],visy[MAXN];
ll fx[MAXN],fy[MAXN],ax[MAXN],ay[MAXN];
ll c[MAXN][MAXN],d[MAXN][MAXN],fac[MAXN];
void work(int n,ll *a,ll *f)
{
	memset(d,0,sizeof(d));
	d[0][0]=1;
	enum(i,1,n)
		enum(j,0,a[i]/2)
			enum(k,j,max(ns,ms))
				d[i][k]=(d[i][k]+1ll*d[i-1][k-j]*c[a[i]-j][j])%MOD;
	enum(i,0,max(ns,ms))f[i]=d[n][i];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int x,y;
	readint(n);readint(m);readint(Q);
	enum(i,1,2*Q)
	{
		readint(x);readint(y);
		visx[x]=1;visy[y]=1;
	}
	c[0][0]=1;
	enum(i,1,max(n,m))
	{
		c[i][0]=1;
		enum(j,1,i)c[i][j]=dmy(c[i-1][j-1]+c[i-1][j]);
	}
	fac[0]=1;
	enum(i,1,max(n,m))fac[i]=fac[i-1]*i%MOD;
	visx[n+1]=visy[m+1]=1;
	int las=1;
	enum(i,1,n+1)
		if(visx[i])
			ax[++nc]=i-las,ns+=i-las,las=i+1;
	las=1;
	enum(i,1,m+1)
		if(visy[i])
			ay[++mc]=i-las,ms+=i-las,las=i+1;
	
	work(nc,ax,fx);
	work(mc,ay,fy);
//enum(i,0,ns/2)cerr<<fx[i]<<" ";cerr<<endl;
//enum(i,0,ms/2)cerr<<fy[i]<<" ";cerr<<endl;
	ll ans=0;
	enum(i,0,ns/2)
		enum(j,0,ms/2)
		{
//cerr<<i<<" "<<j<<":"<<fx[i]*c[ns-2*i][j]%MOD*fy[j]%MOD*c[ms-2*j][i]%MOD*fac[i]%MOD*fac[j]%MOD<<endl;
			ans=(ans+fx[i]*c[ns-2*i][j]%MOD*fy[j]%MOD*c[ms-2*j][i]%MOD*fac[i]%MOD*fac[j])%MOD;
		}
	printf("%lld\n",ans);
	return 0;
}
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
const int MOD=998244353,INV2=(MOD+1)/2;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=140005;

int N,n,ind[MAXN],q[MAXN],sg[MAXN],vis[MAXN];
vector<int> G[MAXN];
int a[MAXN];
void fwt(int *a,int ty)
{
	int t1,t2;
	for(int d=1;d<N;d<<=1)
		for(int i=0;i<N;i+=(d<<1))
			for(int j=0;j<d;j++)
			{
				t1=a[i+j],t2=a[i+j+d];
				a[i+j]=dmy(t1+t2),a[i+j+d]=dmy(t1-t2+MOD);
				if(!ty)a[i+j]=1ll*a[i+j]*INV2%MOD,a[i+j+d]=1ll*a[i+j+d]*INV2%MOD;
			}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	readint(n),readint(E);
	while(E--)readint(u),readint(v),G[u].pb(v),++ind[v];
	int front=1,rear=0;
	for(int i=1;i<=n;++i)if(!ind[i])q[++rear]=i;
	while(front<=rear)
	{
		u=q[front++];
		for(auto v:G[u])
		{
			--ind[v];
			if(!ind[v])q[++rear]=v;
		}
	}
	for(int i=n;i;--i)
	{
		u=q[i];
		for(auto v:G[u])vis[sg[v]]=u;
		while(vis[sg[u]]==u)++sg[u];
		++a[sg[u]];
	}
	for(N=1;N<n;N<<=1);
	int lbd=1ll*qmi(n+1,MOD-2)%MOD;
	for(int i=0;i<N;++i)a[i]=dmy(MOD-1ll*lbd*a[i]%MOD);
	inc(a[0],1);
	fwt(a,1);
	for(int i=0;i<N;++i)a[i]=qmi(a[i],MOD-2);
	fwt(a,0);
	printf("%d\n",dmy(1-1ll*a[0]*qmi(n+1,MOD-2)%MOD+MOD));
	return 0;
}
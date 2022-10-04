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
const int MAXN=100005,W=8,S=800,MAXS=S+5;

int n,a[MAXN],tag[MAXS],f[MAXN];
int blo(int x){return x==1?0:(x>>W)+1;}
int fa(int u)
{
	return max(a[u]-tag[blo(u)],1);
}
int anc(int u)
{
	if(tag[blo(u)]>(1<<W))return fa(u);
	return f[u];
}
void calone(int u,int z)
{
	a[u]=max(a[u]-z,1);
	if(blo(u)==blo(fa(u)))f[u]=f[fa(u)];
	else f[u]=fa(u);
}
void calblo(int u)
{
	if(tag[u]>(1<<W))return;
	int st=(1<<W)*(u-1);
	if(u==1)st=2;
	for(int i=st;blo(i)==u && i<=n;++i)
		if(blo(fa(i))==u)f[i]=f[fa(i)];
		else f[i]=fa(i);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,op,x,y,z;
	readint(n),readint(Q);
	for(int i=2;i<=n;++i)
	{
		readint(a[i]);
		if(blo(i)==blo(a[i]))f[i]=f[a[i]];
		else f[i]=a[i];
	}
	while(Q--)
	{
		readint(op),readint(x),readint(y);
		if(op==1)
		{
			readint(z);
			if(blo(x)==blo(y))
			{
				for(int i=x;i<=y;++i)a[i]=max(a[i]-z,1);
				calblo(blo(x));
			}
			else
			{
				for(int i=x;blo(i)==blo(x);++i)a[i]=max(a[i]-z,1);
				for(int i=blo(x)+1;i<=blo(y)-1;++i)tag[i]=min(tag[i]+z,n);
				for(int i=y;blo(i)==blo(y);--i)a[i]=max(a[i]-z,1);
				for(int i=blo(x);i<=blo(y);++i)calblo(i);
			}
		}
		else
		{
			while(x!=y)
			{
				if(x>y)swap(x,y);
				if(blo(y)>blo(x))y=anc(y);
				else if(anc(x)!=anc(y))x=anc(x),y=anc(y);
				else y=max(a[y]-tag[blo(y)],1);
			}
			printf("%d\n",x);
		}
	}
	return 0;
}
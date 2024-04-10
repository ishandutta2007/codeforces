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
const int MAXN=10000005,MAXM=105,MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}

int n,a[MAXN],c[MAXN],pw2[MAXN];
int prm[MAXN],myp[MAXN],mu[MAXN],pn;
bool notp[MAXN];
void euler(int n)
{
	notp[1]=1;mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!notp[i])prm[++pn]=i,myp[i]=i,mu[i]=-1;
		for(int j=1;j<=pn && i*prm[j]<=n;++j)
		{
			notp[i*prm[j]]=1;
			myp[i*prm[j]]=prm[j];
			if(!(i%prm[j]))
			{
				mu[i*prm[j]]=0;
				break;
			}
			else mu[i*prm[j]]=-mu[i];
		}
	}
}

int b[MAXM],d[MAXM],m;
void dfs(int x,int y,int cur)
{
	if(x>m)
	{
		c[cur]+=y;
		return;
	}
	for(int i=0;i<=d[x];++i)
	{
		dfs(x+1,y,cur);
		cur*=b[x];
	}
}
void work(int x,int y)
{
	m=0;
	while(x>1)
	{
		++m;
		b[m]=myp[x];
		d[m]=0;
		while(!(x%b[m]))++d[m],x/=b[m];
	}
	dfs(1,y,1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,x;
	readint(Q);
	pw2[0]=1;
	for(int i=1;i<=Q;++i)pw2[i]=dmy(pw2[i-1]*2);
	for(int i=1;i<=Q;++i)
	{
		readint(x);
		++a[x];
		chkmax(n,x);
	}
	euler(n);
	for(int i=1;i<=n;++i)
	{
		if(!a[i])continue;
		work(i,a[i]);
	}
//for(int i=1;i<=n;++i)cerr<<c[i]<<" ";cerr<<endl;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(!c[i] || !mu[i])continue;
		int t=dmy(MOD-1ll*pw2[c[i]]*(Q-c[i])%MOD+Q);
		if(mu[i]==1)ans=dmy(ans+t);
		else ans=dmy(ans-t+MOD);
	}
	printf("%d\n",ans);
	return 0;
}
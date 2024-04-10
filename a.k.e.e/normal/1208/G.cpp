#include <bits/stdc++.h>
#define end xtqakioi
#define hash xtqtxdy

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
inline void chkmax(int &x,int y){x<y?x=y:0;}
inline void chkmin(int &x,int y){x>y?x=y:0;}
int readint()
{
    int x=0;char c;
    for(c=getchar();!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    return x;
}
const int MAXN=1000005,INF=0x3f3f3f3f;

int n,k,prm[MAXN],phi[MAXN],pn;
bool notp[MAXN];
int a[MAXN];

inline bool cmp(int x,int y){return phi[x]<phi[y];}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	n=readint();k=readint();
	if(k==1)return 0*printf("3\n");
	if(n<=5)
	{
		int ans=1;
		for(int i=3;i<=k+2;i++)
			ans+=i-1;
		return 0*printf("%d\n",ans);
	}
	phi[1]=1;notp[1]=1;
	enum(i,2,n)
	{
		if(!notp[i])prm[++pn]=i,phi[i]=i-1;
		for(int j=1;j<=pn && i*prm[j]<=n;j++)
		{
			notp[i*prm[j]]=1;
			if(i%prm[j])phi[i*prm[j]]=phi[i]*(prm[j]-1);
			else {phi[i*prm[j]]=phi[i]*prm[j];break;}
		}
	}
	sort(phi+1,phi+n+1);
	ll ans=0;
	for(int i=1;i<=k+2;i++)ans+=phi[i];
	printf("%lld\n",ans);
    return 0;
}
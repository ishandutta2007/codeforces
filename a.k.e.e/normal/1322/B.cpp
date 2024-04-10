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
const int MAXM=10000005,MAXK=25;

int n,a[1<<MAXK],suf[1<<MAXK];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int res=0,x;
	readint(n);
	for(int i=1;i<=n;++i)readint(x),++a[x];
	for(int j=MAXK-1;j>=0;--j)
	{
		ll ans=0;
		suf[(1<<(j+1))]=0;
		for(int i=(1<<(j+1))-1;i>=0;--i)
		{
			suf[i]=suf[i+1]+a[i];
			if((i*2)&(1<<j))ans-=a[i];
		}
//if(j<=2){for(int i=0;i<(1<<(j+1));++i)cerr<<suf[i]<<" ";cerr<<endl;}
		int l=(1<<j),r=(1<<(j+1))-1;
		for(int i=0;i<(1<<(j+1));++i)
		{
			if(l<r)ans+=1ll*a[i]*(suf[l]-suf[r+1]);
			else ans+=1ll*a[i]*(suf[l]+suf[0]-suf[r+1]);
			--l,--r;
			if(l<0)l+=(1<<(j+1));
		}
//if(j<=2)cerr<<ans<<endl;
		if(ans&2)res^=(1<<j);
		for(int i=0;i<(1<<j);++i)a[i]+=a[i+(1<<j)];
	}
	cout<<res<<endl;
	return 0;
}
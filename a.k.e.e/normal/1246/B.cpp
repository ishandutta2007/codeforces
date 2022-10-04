#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define k first
#define b second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005;

ll qmi(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1,x=x*x)
		if(y&1)ans=ans*x;
	return ans;
}

int n,k,m;
ll a[MAXN],f[MAXN],cnt[MAXN];
map<pii,ll> mp;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	int x;
	readint(n);readint(k);
	enum(i,1,n)
	{
		readint(x);++a[x];
		chkmax(m,x);
	}
	if(k>=3)
	{
		ll ans=0;
		enum(i,1,m)
		{
			ll t=qmi(i,k);
			if(t>1ll*m*m)break;
			enum(j,max(t/m-1,1ll),m)
			{
				if(1ll*j*j>t)break;
				if(!(t%j))
				{
					if(1ll*j*j==t)ans+=a[j]*(a[j]-1)/2;
					else if(t/j<=m)ans+=a[j]*a[t/j];
				}
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(k==2)
	{
		ll ans=0;
		enum(i,1,m)f[i]=i;
		enum(i,2,m)
		{
			if(i*i>m)break;
			for(int j=i;j<=m;j+=i)
				while(!(f[j]%(i*i)))f[j]/=(i*i);
		}
		enum(i,1,m)cnt[f[i]]+=a[i];
		enum(i,1,m)
			ans+=1ll*cnt[i]*(cnt[i]-1)/2;
		printf("%lld\n",ans);
		return 0;
	}
	/*ll ans=0;
	enum(i,1,m)f[i]=i;
	enum(i,1,m)
	{
		if(i*i*i>m)break;
		for(int j=i;j<=m;j+=i)
			while(!(f[j]%(i*i*i)))f[j]/=(i*i);
	}
	enum(i,1,m)cnt[f[i]]+=a[i];
	enum(i,1,m)
		ans+=1ll*cnt[i]*(cnt[i]-1);
	printf("%lld\n",ans);*/
    return 0;
}
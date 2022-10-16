#include<bits/stdc++.h>
// Basic typedefs 
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
// STL function usage
using std::min;
using std::max;
using std::swap;
using std::reverse;
using std::sort;
// STL container usage
using std::vector;
using std::set;
using std::multiset;
using std::map;
using std::deque;
using std::queue;
// Basic pair
struct pii
{
	int x,y;
	pii(){}
	pii(int xx,int yy){x=xx,y=yy;}
};
bool operator<(const pii x,const pii y)
{if(x.x^y.x)return x.x<y.x;return x.y<y.y;}
// Main

int n,m,k;
int a[1111111];
ll v[1111111];
char s[1111111];
pii P[1111111];
int cnt[111];
const ll mod=1e9+7; 
void ins(ll x)
{
	for(register int i=0;x;x>>=1,i++)
	{
		cnt[i]+=(x&1);
	}
}
void exec()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=0;i<=65;i++)cnt[i]=0;
	for(i=1;i<=n;i++)scanf("%lld",v+i);
	for(i=1;i<=n;i++)
	{
		ins(v[i]);
	}ll ans=0;
	for(i=1;i<=n;i++)
	{
		ll S1=0,S2=0,x=v[i];
		for(ii=0;ii<62;x>>=1,ii++)
		{
			ll V=(1ll<<ii)%mod;
			if(x&1)
			{
				(S1+=V*cnt[ii])%=mod;
				(S2+=V*n)%=mod;
			}else (S2+=V*cnt[ii])%=mod;
		}//printf("%lld %lld\n",S1,S2);
		(ans+=S1*S2)%=mod;
	}printf("%lld\n",ans);
} 
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Good bye 2020!
Never forget your days as an OIer, 3.141592653.
Always continue and never break...
*/
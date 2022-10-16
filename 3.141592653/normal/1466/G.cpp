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

int n,m,k,ls;
int a[1111111];
ll v[1111111];
char s[1111111],t[1111111],u[1111111];
pii P[1111111];
const ll mod=1e9+7,inv2=(mod+1)>>1;
ll ans=0;
char tp[24][1011111];
ll cnt[40][111111];
ll pw2[1111111],ipw2[1111111];
void init()
{
	int Mxt=1e6+10;
	for(register int i=pw2[0]=ipw2[0]=1;i<=Mxt;i++)
		pw2[i]=pw2[i-1]*2%mod,
		ipw2[i]=ipw2[i-1]*inv2%mod;
}
ll calctim(int ths,int mxs,char ts)
{
	int rs=ts-96;
	//printf("%d[%lld] %d[%lld] c=%d\n",
	//ths,cnt[rs][ths],
	//mxs,cnt[rs][mxs+1],
	//rs);
	return(cnt[rs][ths]+mod-
	cnt[rs][mxs+1])*ipw2[n-mxs]%mod;
}
ll calc(int dep,int len)
{
	if(len==1)
	{
		if(dep>k)return 0;
		return calctim(dep,k,tp[dep][1]);
	}register int i;
	ll ret=0;
	int ld=0;
	for(i=2;i<=len;i+=2)
		if(tp[dep][i]!=t[dep])
			goto EXT1;
	for(i=1;i<=len;i+=2)
	{
		tp[dep+1][++ld]=tp[dep][i];
	}ret+=calc(dep+1,ld);
	EXT1:ld=0;
	for(i=1;i<=len;i+=2)
		if(tp[dep][i]!=t[dep])
			goto EXT2;
	for(i=2;i<=len;i+=2)
		tp[dep+1][++ld]=tp[dep][i];
	ret+=calc(dep+1,ld);
	EXT2:return ret%mod;
}
void initcnt()
{
	register int i,ii;
	for(i=n;i;i--)
	{
		for(ii=1;ii<=26;ii++)
			cnt[ii][i]=cnt[ii][i+1];
		//printf("? %d\n",t[i]-96);
		(cnt[(int)(t[i]-96)][i]+=pw2[n-i])%=mod;
	}
}
void solve()
{
	ans=0;
	int l=strlen(u+1);
	register int i,ii;
	for(i=1;i<=ls+1;i++)
	{
		//if(!check(i))continue;
		// check() expanded as : 
		for(ii=1;ii<=l;ii++)
		{
			int res=(ii+ls-i)%(ls+1)+1;
			if(res<=ls)
			{
				if(u[ii]!=s[res])goto CONT;
			}
		}
		//fprintf(stderr,">> %d\n",i);
		if(i>l)(ans+=pw2[k])%=mod;
		else
		{
			int cl=0;
			for(ii=i;ii<=l;ii+=ls+1)
				tp[1][++cl]=u[ii];
			(ans+=calc(1,cl))%=mod;
		}
		CONT:;
	}printf("%lld\n",ans%mod);
}
void exec()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1),ls=strlen(s+1);
	initcnt();
	register int i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%s",&k,u+1);
		solve();
	}
}
int main()
{
	init();
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Good bye 2020!
Never forget your days as an OIer, 3.141592653.
Always continue and never break...
*/
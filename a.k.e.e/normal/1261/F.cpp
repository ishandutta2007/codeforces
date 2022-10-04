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
const int MAXN=4800005,MOD=998244353;
typedef pair<ll,ll> pll;

int n,m;
pll a[MAXN];
void query(int dep,ll l,ll r,ll ql,ll qr)
{
	if(l==ql && r==qr){a[++n]=mp(dep,l>>dep);return;}
	ll mid=(l+r)>>1;
	if(qr<=mid)return query(dep-1,l,mid,ql,qr);
	if(ql>mid)return query(dep-1,mid+1,r,ql,qr);
	query(dep-1,l,mid,ql,mid);query(dep-1,mid+1,r,mid+1,qr);
}
int ch[MAXN][2],stot=1;
bool vis[MAXN];
void walk(int &id,int dep,ll l,ll r,ll ql,ll qr,ll x)
{
	if(!id)id=++stot;
	if(l==ql && r==qr){vis[id]=1;return;}
	--dep;
	ll mid=(l+r)>>1;
	if(!(x&(1ll<<dep)))
	{
		if(qr<=mid)walk(ch[id][0],dep,l,mid,ql,qr,x);
		else if(ql>mid)walk(ch[id][1],dep,mid+1,r,ql,qr,x);
		else walk(ch[id][0],dep,l,mid,ql,mid,x),walk(ch[id][1],dep,mid+1,r,mid+1,qr,x);
	}
	else
	{
		x^=(1ll<<dep);
		if(qr<=mid)walk(ch[id][1],dep,mid+1,r,ql^(1ll<<dep),qr^(1ll<<dep),x);
		else if(ql>mid)walk(ch[id][0],dep,l,mid,ql^(1ll<<dep),qr^(1ll<<dep),x);
		else walk(ch[id][1],dep,mid+1,r,ql^(1ll<<dep),mid^(1ll<<dep),x)
			,walk(ch[id][0],dep,l,mid,(mid+1)^(1ll<<dep),qr^(1ll<<dep),x);
	}
}
ll final(int id,ll l,ll r)
{
	if(!id)return 0;
	if(vis[id])return ((r-l+1)%MOD)*((l+r)%MOD)%MOD*(MOD+1)/2%MOD;
	ll mid=(l+r)>>1;
	return (final(ch[id][0],l,mid)+final(ch[id][1],mid+1,r))%MOD;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	ll x,y;
	int Q;readint(Q);
	while(Q--)
	{
		readint(x);readint(y);
		query(60,0,(1ll<<60)-1,x,y);
	}
	readint(m);
	for(int i=1;i<=m;++i)
	{
		readint(x),readint(y);
		for(int j=1;j<=n;++j)
		{
			int rt=1;
			ll tx=x>>a[j].x,ty=y>>a[j].x;
			walk(rt,60,0,(1ll<<60)-1,tx<<a[j].x,((ty+1)<<a[j].x)-1,a[j].y<<a[j].x);
		}
	}
	printf("%lld\n",final(1,0,(1ll<<60)-1)%MOD);
	return 0;
}
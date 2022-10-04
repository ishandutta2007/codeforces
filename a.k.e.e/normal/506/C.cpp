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
const int MAXN=100005;

int n,m,k;
ll w,h[MAXN],a[MAXN],c[MAXN];
priority_queue<pii,vector<pii>,greater<pii> > pq;
bool check(ll mid)
{
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;++i)
	{
		c[i]=mid;
		if(mid-m*a[i]<h[i])pq.push(mp(mid/a[i],i));
	}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=k;++j)
		{
			if(pq.empty())return 1;
			pii p=pq.top();pq.pop();
			if(p.x<i)return 0;
			c[p.y]+=w;
			if(c[p.y]-m*a[p.y]<h[p.y])pq.push(mp(c[p.y]/a[p.y],p.y));
		}
	return pq.empty();
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);readint(m);readint(k);readint(w);
	for(int i=1;i<=n;++i)readint(h[i]),readint(a[i]);
	ll L=1,R=1ll<<60,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
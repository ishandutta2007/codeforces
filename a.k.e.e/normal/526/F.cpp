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
const int MAXN=300005,MAXK=19;

int n,a[MAXN],bmin[MAXN],bmax[MAXN];
int _log2[MAXN],rmax[MAXN][MAXK],rmin[MAXN][MAXK],sum[MAXN*2];
void init()
{
	_log2[1]=0;
	for(int i=2;i<=n;++i)_log2[i]=_log2[i>>1]+1;
	for(int i=1;i<=n;++i)rmax[i][0]=rmin[i][0]=a[i];
	for(int j=1;j<MAXK;++j)
		for(int i=1;i<=n-(1<<j)+1;++i)
			rmax[i][j]=max(rmax[i][j-1],rmax[i+(1<<(j-1))][j-1]),
			rmin[i][j]=min(rmin[i][j-1],rmin[i+(1<<(j-1))][j-1]);
}
inline int qmax(int l,int r)
{
	int t=_log2[r-l+1];
	return max(rmax[l][t],rmax[r-(1<<t)+1][t]);
}
inline int qmin(int l,int r)
{
	int t=_log2[r-l+1];
	return min(rmin[l][t],rmin[r-(1<<t)+1][t]);
}
ll solve(int l,int r)
{
	if(l==r)return 1;
	int mid=(l+r)>>1;
	ll ans=0;
	for(int i=mid;i>=l;--i)
	{
		int u=qmax(i,mid),v=qmin(i,mid),j=i+u-v;
		if(j>mid && j<=r && qmax(mid+1,j)<=u && qmin(mid+1,j)>=v)++ans;
	}
	for(int j=mid+1;j<=r;++j)
	{
		int u=qmax(mid+1,j),v=qmin(mid+1,j),i=j-u+v;
		if(i<=mid && i>=l && qmax(i,mid)<=u && qmin(i,mid)>=v)
			ans+=(qmax(i,mid)<u || qmin(i,mid)>v);
	}
	int lj=mid+1,rj=mid;
	for(int i=mid;i>=l;--i)
	{
		while(lj<=r && qmax(mid+1,lj)<=qmax(i,mid))--sum[lj-qmax(mid+1,lj)+n],++lj;
		while(rj<r && qmin(mid+1,rj+1)>=qmin(i,mid))++rj,++sum[rj-qmax(mid+1,rj)+n];
		if(lj<=rj)ans+=sum[i-qmin(i,mid)+n];
	}
	for(int j=mid+1;j<=r;++j)sum[j-qmax(mid+1,j)+n]=0;
	lj=mid+1,rj=mid;
	for(int i=mid;i>=l;--i)
	{
		while(lj<=r && qmin(mid+1,lj)>=qmin(i,mid))--sum[lj+qmin(mid+1,lj)],++lj;
		while(rj<r && qmax(mid+1,rj+1)<=qmax(i,mid))++rj,++sum[rj+qmin(mid+1,rj)];
		if(lj<=rj)ans+=sum[i+qmax(i,mid)];
	}
	for(int j=mid+1;j<=r;++j)sum[j+qmin(mid+1,j)]=0;
	return ans+solve(l,mid)+solve(mid+1,r);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	#endif
	int u;
	readint(n);
	for(int i=1;i<=n;++i)readint(u),readint(a[u]);
	init();
	printf("%lld\n",solve(1,n));
	return 0;
}
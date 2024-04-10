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
const int MAXN=200005;

int n,m,a[MAXN],p[MAXN],res[MAXN];
vector<int> v[MAXN];
vector<pii> q[MAXN];
int c[MAXN];
void add(int x,int d){for(;x<=n;x+=(x&-x))c[x]+=d;}
int query(int x){int ans=0;for(;x;x-=(x&-x))ans+=c[x];return ans;}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);
		p[i]=a[i];
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(p+1,p+n+1,a[i])-p;
	for(int i=1;i<=n;++i)v[a[i]].pb(i);
	readint(m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		readint(x),readint(y);
		q[x].pb(mp(y,i));
	}
	int cur=0;
	for(int i=n;i;--i)
		for(auto j:v[i])
		{
			++cur;
			add(j,1);
			for(auto t:q[cur])
			{
				int L=1,R=n,mid,pos=n;
				while(L<=R)
				{
					mid=(L+R)>>1;
					if(query(mid)>=t.x)pos=mid,R=mid-1;
					else L=mid+1;
				}
				res[t.y]=p[a[pos]];
			}
		}
	for(int i=1;i<=m;++i)printf("%d\n",res[i]);
	return 0;
}
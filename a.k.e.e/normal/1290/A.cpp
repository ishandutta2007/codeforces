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
const int MAXN=3505;

int n,m,k,a[MAXN],b[MAXN],pos[MAXN];
bool check(int mid)
{
	int cnt=0;
	for(int i=1;i<=m;++i)if(b[i]<mid)pos[++cnt]=i;
	pos[cnt+1]=m+1;
	for(int i=0;i<=cnt;++i)if(pos[i]+(m-pos[i+1]+1)<=k)return 1;
	return 0;
}
void solve()
{
	readint(n),readint(m),readint(k);
	chkmin(k,m-1);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=m;++i)b[i]=max(a[i],a[i+n-m]);
	int L=1,R=1000000000,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d\n",ans);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
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

int n,Min[MAXN],Max[MAXN];
int a[MAXN],b[MAXN];
bool hv[MAXN];
int m;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		int k,x;
		Min[i]=1<<30,Max[i]=0;
		readint(k);
		while(k--)
		{
			readint(x);
			if(x>Min[i])hv[i]=1;
			chkmin(Min[i],x);
			chkmax(Max[i],x);
		}
		if(!hv[i])a[++m]=Min[i],b[m]=Max[i];
	}
	ll ans=1ll*n*n;
	sort(a+1,a+m+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=m;++i)
		ans-=upper_bound(b+1,b+m+1,a[i])-b-1;
	printf("%lld\n",ans);
	return 0;
}
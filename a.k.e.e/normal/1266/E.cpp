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

int n,a[MAXN];
map<pii,int> b;
int cnt[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	ll ans=0;
	int Q,x,y,z;
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),ans+=a[i];
	readint(Q);
	while(Q--)
	{
		readint(x),readint(y),readint(z);
		pii p=mp(x,y);
		if(b.count(p) && b[p])
		{
			int u=b[p];
			ans-=max(0,a[u]-cnt[u]);
			--cnt[u];
			ans+=max(0,a[u]-cnt[u]);
		}
		b[p]=z;
		ans-=max(0,a[z]-cnt[z]);
		++cnt[z];
		ans+=max(0,a[z]-cnt[z]);
		printf("%I64d\n",ans);
	}
	return 0;
}
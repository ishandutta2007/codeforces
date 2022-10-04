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

int n,a[MAXN];
int fun(int x)
{
	int res=0;
	for(int i=0;i<=30;++i)
		if(x&(1<<i))res=i;
	return res;
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	int ans=-1;
	for(int i=2;i<=n;++i)
		if(a[i]<a[i-1])
			chkmax(ans,fun(a[i-1]-a[i])),a[i]=a[i-1];
	printf("%d\n",ans+1);
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
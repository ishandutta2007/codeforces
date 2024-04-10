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
const int MAXN=25;

ll k;
int m,a[MAXN],cnt[MAXN];
ll work(int m,int *a)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=m;++i)++cnt[a[i]];
	sort(cnt+1,cnt+m+1);
	ll ans=1;
	int cur=1;
	for(int i=m;i;--i)
	{
		ans=1ll*ans*(i-a[i]+1);
		while(cur<=m && (!cnt[cur] || !(ans%cnt[cur])))
			if(!cnt[cur])++cur;
			else ans/=cnt[cur],--cnt[cur];
	}
	return ans;
}
void solve()
{
	m=0;
	readint(k);
	a[++m]=1;
	for(int i=2;k;++i)
	{
		a[++m]=k%i+1;
		k/=i;
	}
	sort(a+1,a+m+1);
	printf("%lld\n",work(m,a)-work(m-1,a+1)-1);
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
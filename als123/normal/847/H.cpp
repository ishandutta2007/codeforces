#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 210000;

int n,a[maxn];
ll pre[maxn],suf[maxn];
int mp[maxn],ms[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int now=0;
	for(int i=1;i<=n;i++)
	{
		int pnow=max(now+1,a[i]);
		pre[i]=pre[i-1]+(ll)(pnow-a[i]);
		mp[i]=now=pnow;
	}now=0;
	for(int i=n;i>=1;i--)
	{
		int pnow=max(now+1,a[i]);
		suf[i]=suf[i+1]+(ll)(pnow-a[i]);
		ms[i]=now=pnow;
	}
	ll ans=min(pre[n],suf[1]);
	for(int i=2;i<n;i++)
	{
		int p1=mp[i-1],p2=ms[i+1];
		int pm=max(p1,p2)+1; pm=max(pm,a[i]);
		ans=min(ans,pre[i-1]+suf[i+1]+(ll)(pm-a[i]));
	}
	printf("%I64d\n",ans);
	
	return 0;
}
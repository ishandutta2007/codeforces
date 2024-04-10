#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 100005;

int l[maxn],r[maxn],ins[maxn];
int n,a[maxn],dis[maxn];
LL s[maxn],ans[maxn],cur=0;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("array.in","r",stdin);
		freopen("array.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&dis[i]);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=n;i>=1;i--) {
		int x=dis[i];
		ans[i]=cur;ins[x]=true;
		int L=ins[x-1]?l[x-1]:x;
		int R=ins[x+1]?r[x+1]:x;
		l[R]=L;r[L]=R;cur=max(cur,s[R]-s[L-1]);
	}
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
}
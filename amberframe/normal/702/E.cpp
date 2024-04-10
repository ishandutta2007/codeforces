#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;
const int inf = 1<<30;
int n;LL k;
struct st {
	int to[maxn];
	LL sum[maxn];
	int mi[maxn];
	void operator*=(const st v) {
		for (int i=0;i<n;i++) {
			sum[i]+=v.sum[to[i]];
			mi[i]=min(mi[i],v.mi[to[i]]);
			to[i]=v.to[to[i]];
		}
	}
}ans,tmp;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("graph.in","r",stdin);
		freopen("graph.out","w",stdout);
	#endif
	scanf("%d %I64d",&n,&k);
	for (int i=0;i<n;i++)
		scanf("%d",&tmp.to[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&tmp.mi[i]);
	for (int i=0;i<n;i++)
		tmp.sum[i]=tmp.mi[i];
	for (int i=0;i<n;i++)
		ans.to[i]=i,ans.mi[i]=inf;
	for (;k;k>>=1,tmp*=tmp)
		if (k&1) ans*=tmp;
	for (int i=0;i<n;i++)
		printf("%I64d %d\n",ans.sum[i],ans.mi[i]);
	return 0;
}
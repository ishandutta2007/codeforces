#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<LL,LL> mp;
#define pb push_back

const int maxn = 105;
const LL mod = 1e9+7;

LL a[maxn];int n;LL K;
LL cur,ans=1ll;
vector<mp> chg;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("partition.in","r",stdin);
		//freopen("partition.out","w",stdout);
	#endif
	scanf("%d %lld",&n,&K);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);cur+=a[i];K+=a[i];
		LL las=a[i];
		for (LL j=1;j<a[i];) {
			LL o=(a[i]-1)/j;
			LL r=(a[i]-1)/o+1;
			LL nw=(a[i]-1)/r+1;
			chg.pb(mp(r,nw-las));
			las=nw;j=r;
		}
	}
	sort(chg.begin(),chg.end());
	LL las=1;
	for (int i=0;i<chg.size();i++)
	{
		LL o=min(chg[i].first-1ll,K/cur);
		if (o>=las) ans=max(ans,o);
		cur+=chg[i].second;las=chg[i].first;
	}
	LL o=K/cur;
	if (o>=las) ans=max(ans,o);
	printf("%lld\n",ans);
	return 0;
}
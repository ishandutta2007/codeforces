#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>

using namespace std;
#define pb push_back
typedef long long LL;
const int maxn = 100005;
const LL inf = 1e15;
map<LL,int> s;

LL a[maxn];int n,k;LL ans;
LL Abs(LL x){return x>0?x:-x;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("chemicals.in","r",stdin);
		freopen("chemicals.out","w",stdout);
	#endif
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=1;i<=n;i++) {
		s[a[i-1]]++;
		if (k==1) ans+=s[a[i]-1];
		else if (k==-1) ans+=s[a[i]-1]+s[a[i]+1];
		else {
			LL cur=1;
			while (Abs(cur)<=inf) {
				ans+=s[a[i]-cur];cur*=k;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
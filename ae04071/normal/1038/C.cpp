#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;

int n;
pii a[200000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i].first);
	for(int i=0;i<n;i++) scanf("%d",&a[i+n].first);
	for(int i=0;i<n;i++) a[i].second=0, a[i+n].second=1;
	sort(a,a+n+n);

	lli ans[2]={0,};
	int cur=0;
	for(int i=n*2-1;i>=0;i--) {
		if(a[i].second == cur) ans[cur] += a[i].first;
		cur^=1;
	}
	printf("%lld\n",ans[0]-ans[1]);

	return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <assert.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,arr[300001],m,a,b,ai,bi;
lli cache[5001][5001];

lli DP(int i,int j) {
	lli &ret=cache[i][j];
	if(ret!=-1) return ret;

	int idx=ai*(a-i) + bi*(b-j);
	ret=0;
	if(i+j==1) return ret;
	
	if(i) ret = max(ret, DP(i-1,j)+arr[idx+ai]-arr[idx+ai-1]);
	if(j) ret = max(ret, DP(i,j-1)+arr[idx+bi]-arr[idx+bi-1]);
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	sort(arr,arr+n);

	lli ans=0;
	for(int i=0;i<n-1;i++) ans+=arr[i+1]-arr[i];

	a=n%m,b=m-a;
	bi=n/m,ai=n/m+1;
	memset(cache,-1,sizeof(cache));
	printf("%lld\n",ans - DP(a,b));

	return 0;
}
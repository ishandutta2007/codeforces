#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int inf=1e9;
int n;
lli arr[100020];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",arr+i);
	arr[0] = -4ll*inf; arr[n+1] = 4ll*inf;

	for(int i=1;i<=n;i++) {
		printf("%lld %lld\n",min(1ll*arr[i]-arr[i-1],1ll*arr[i+1]-arr[i]),max(1ll*arr[n]-arr[i],1ll*arr[i]-arr[1]));	
	}

	return 0;
}
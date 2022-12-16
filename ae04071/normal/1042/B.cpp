#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;
const int inf=1e9+10;

int n,a[1000],s[1000];
char str[10];
int dp[1001][8];

int DP(int idx,int state) {
	int &ret=dp[idx][state];
	if(ret!=-1) return ret;

	if(state == (1<<3)-1) return ret=0;
	if(idx==n) return ret=inf;
	
	ret=inf;
	ret = min(ret, DP(idx+1,state));
	ret = min(ret, DP(idx+1,state | s[idx]) + a[idx]);
	return ret;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d%s",a+i,str);

		int m=strlen(str);
		for(int j=0;j<m;j++) s[i] |= 1<<(str[j]-'A');
	}
	memset(dp,-1,sizeof(dp));
	int val=DP(0,0);
	if(val>=inf) puts("-1");
	else printf("%d\n",val);
	return 0;
}
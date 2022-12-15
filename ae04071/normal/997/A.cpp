#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <cmath>

#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const double PI=acos(-1);
const lli mod=1e9+7;

int n;
char str[300001];

int main() {
	int x,y,cnt=0;
	scanf("%d%d%d%s",&n,&x,&y,str);
	for(int i=0;i<n;i++) {
		if(str[i]=='1') continue;
		
		int j;
		for(j=i;j<n && str[j]=='0';j++);
		cnt++;
		i=j-1;
	}
	if(cnt==0) {
		puts("0");
		return 0;
	}

	lli ans=1e16;
	for(int i=1;i<=cnt;i++) {
		ans=min(ans, 1ll*max(cnt-i,0)*x + 1ll*y*i);
	}
	printf("%lld\n",ans);
	
	return 0;
}
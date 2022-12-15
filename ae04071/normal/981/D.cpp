#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <set>
#include <cstring>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))

using namespace std;
typedef pair<int,int> pii;
typedef long long lli;

int k,n;
lli arr[51], tar, sum[51];
int cache[61][61];

int DP(int idx,int c) {
	int &ret=cache[idx][c];
	if(ret!=-1) return ret;

	if(idx==n) return c==0;
	
	lli s=0;
	ret=0;
	for(int i=idx;i<n;i++) {
		s += arr[i];
		if( (s & tar) == tar) {
			ret = DP(i+1,c-1);
			if(ret==1) return ret;
		}
	}
	return ret;
}
bool check(lli val) {
	tar = val;
	memset(cache,-1,sizeof(cache));
	return DP(0,k)==1;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);

	lli ans=0;
	for(int i=60;i>=0;i--) {
		if(check(ans | (1ll<<i))) ans |= (1ll<<i);
	}
	printf("%lld\n",ans);
	
	return 0;
}
#include <cstdio>
#include <cstring>

typedef long long lli;
const lli MOD=1e9+7;
int n,k,d;
lli cache[201][2];

lli DP(int val,int flag) {
	lli &ret=cache[val][flag];
	if(ret!=-1) return ret;
	if(val>n) return ret=0;
	if(val==n) {
		return ret=(flag==1);
	}
	ret=0;
	for(int i=1;i<=k;i++) {
		ret=(ret+DP(val+i,flag|(i>=d)))%MOD;
	}
	return ret;
}
int main() {
	scanf("%d%d%d",&n,&k,&d);
	memset(cache,-1,sizeof(cache));
	printf("%lld\n",DP(0,0));
	return 0;
}
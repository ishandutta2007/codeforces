#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long lli;

int main() {
	lli x,y;
	scanf("%lld%lld",&x,&y);
	
	if(x<y) {
		puts("-1");
		return 0;
	} else if(x==y) {
		printf("%lld\n",y);
		return 0;
	}

	double ans=1e18;
	lli k=(x-y)/(2*y);
	if(k>0) {
		ans = min(ans,1.0*(x-y)/(2*k));
	}
	k=(x+y)/(2*y);
	if(k>0) {
		ans=min(ans,1.0*(x+y)/(2*k));
	}
	printf("%.10lf\n",ans);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
typedef long long ll;
const int mxn = 2e5 + 10;
int main(){
	int n,k,x;
	ll xx = 1;
	scanf("%d %d %d",&n,&k,&x);
	rep(i,0,k) xx *= x;
	ll as[mxn], orl[mxn], orr[mxn];
	orl[0] = orr[n] = 0;
	rep(i,0,n){
		scanf("%lld",as+i);
		orl[i+1] = orl[i] | as[i];
	}
	rrep(i,0,n)
		orr[i] = orr[i+1] | as[i];
	ll ans = 0;
	rep(i,0,n)
		ans = max(ans, orl[i] | (as[i]*xx) | orr[i+1]);
	printf("%lld\n",ans);
}
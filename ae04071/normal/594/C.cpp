#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli = long long;
using pll = pair<lli,lli>;

const lli inf = 5000000000000000000ll + 1;

int n,m;
pll a[100000],b[100000];
lli t[100000];

lli f(int l,int r) {
	lli ret = inf, w = max(a[n-r-1].fi - a[l].fi,2ll);
	for(int i=l;i<n-r;i++) t[i] = a[i].se;
	sort(t+l,t+n-r);
	for(int i=l,j=n-m+l-1;j<n-r;i++,j++) {
		ret = min(ret, w * max(t[j]-t[i],2ll));
	}

	return ret;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		lli q,w,e,r;
		scanf("%lld%lld%lld%lld", &q, &w, &e, &r);
		a[i].fi = e+q; a[i].se = r+w;
	}
	sort(a,a+n);

	lli ans = inf;
	for(int a=0;a<=m;a++) for(int b=0;a+b<=m;b++) {
		ans = min(ans, f(a,b));
	}

	printf("%lld\n",ans/4);

	return 0;
}
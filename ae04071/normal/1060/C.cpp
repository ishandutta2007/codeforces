#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli inf=1e15;

lli a[2001],b[2001],t;
int n,m;
lli val[2001];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int j=1;j<=m;j++) scanf("%lld",&b[j]);
	scanf("%lld",&t);

	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int j=1;j<=m;j++) b[j]+=b[j-1];

	for(int i=1;i<=m;i++) val[i] = 1e15;
	for(int i=1;i<=m;i++) for(int j=i;j<=m;j++) {
		val[j-i+1] = min(val[j-i+1],b[j]-b[i-1]);
	}
	for(int i=m-1;i;i--) val[i]=min(val[i],val[i+1]);
	
	int ans=0;
	for(int r1=1;r1<=n;r1++) for(int r2=r1;r2<=n;r2++) {
		int lo=0,up=m+1;
		while(up-lo>1) {
			int md=(lo+up)>>1;
			if(val[md]*(a[r2]-a[r1-1])<=t) lo=md;
			else up=md;
		}
		ans=max(ans,lo*(r2-r1+1));
	}
	printf("%d\n",ans);

	return 0;
}
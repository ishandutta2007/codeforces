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

int a[100000],b[100000],n;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",a+i,b+i);

	sort(a,a+n);
	sort(b,b+n);

	lli ans=n;
	for(int i=0;i<n;i++) ans+=max(a[i],b[i]);
	printf("%lld\n",ans);
	
	return 0;
}
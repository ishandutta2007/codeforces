#include <bits/stdc++.h>

using namespace std;
typedef long long lli;
const lli inf=1e15;
int n,w;
lli arr[1001];

int main() {
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++) scanf("%lld",arr+i),arr[i]+=arr[i-1];

	lli mx=0,mn=inf;
	for(int i=1;i<=n;i++) {
		mx=max(mx,arr[i]);
		mn=min(mn,arr[i]);
	}
	
	lli l=max(0ll,-mn),r=w-mx;
	if(l>r) puts("0");
	else printf("%lld\n",r-l+1);
	
	return 0;
}
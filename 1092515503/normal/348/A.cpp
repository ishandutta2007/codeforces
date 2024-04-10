#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mx,s,t;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&t),s+=t,mx=max(mx,t);
	printf("%I64d\n",max((s-1)/(n-1)+1,mx));
	return 0;
}
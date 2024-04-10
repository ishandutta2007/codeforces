#include<bits/stdc++.h>
using namespace std;
long long a[9999999];
int main(){
	int T,n,i;
	long long k,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;++i)scanf("%lld",a+i);
		sort(a+1,a+n+1),d=a[2]-a[1];
		for(i=3;i<=n;++i)d=__gcd(d,a[i]-a[i-1]);
		if((k-a[1])%d==0)puts("YES");else puts("NO");
	}
	return 0;
}
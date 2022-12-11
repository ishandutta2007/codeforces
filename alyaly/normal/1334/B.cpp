#include<bits/stdc++.h>
#define eps 0.000000001
using namespace std;
int T,n,p;
double a[100001],s[100001],K;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		p=lower_bound(a+1,a+n+1,K)-a;
		if(p<=n) while(p>=2&&(a[p-1]+s[n]-s[p-1])*1.0/(n-p+2)>=K-eps) p--;
		printf("%d\n",n-p+1);
	}
	return 0;
}
/*
10 13
RLLRLRRLRL
*/
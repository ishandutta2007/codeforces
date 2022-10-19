#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,num[100011],s[100011],mx,mxp;
signed main(){
	scanf("%lld%lld",&n,&k),num[n+1]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+num[i];
//	for(int i=1;i<=n;i++)printf("%lld %lld\n",num[i],s[i]);
	for(int i=1;i<=n;i++){
		if(num[i]==num[i+1])continue;
		int l=1,r=i;
		while(l!=r){
			int mid=(l+r)>>1;
			if(num[i]*(i-mid+1)-(s[i]-s[mid-1])<=k)r=mid;
			else l=mid+1;
		}
//		printf("%lld:%lld\n",i,l);
		if(mx<i-l+1)mx=i-l+1,mxp=num[i];
	}
	printf("%lld %lld\n",mx,mxp);
	return 0;
}
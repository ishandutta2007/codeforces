#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1000003],b;
vector<int>v[500003];
long long calc(int x){
	long long ans=0;
	for(int i=0;i<x;i++){
		long long lst[2]={0,-1145141919810233},pre[2];
		for(int j=i;j<n;j+=x){
			pre[0]=max(lst[0]+a[j],lst[1]-a[j]);
			pre[1]=max(lst[1]+a[j],lst[0]-a[j]);
			lst[0]=pre[0];lst[1]=pre[1];
		}ans+=pre[0];
	}
	return ans;
}
int main(){
	cin>>T;
	while(T--){
		int gcd=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<m;i++){
			int b;
			scanf("%d",&b);
			gcd=__gcd(b,gcd);
		}
		long long ans=calc(gcd);
		for(int i=0;i<gcd;i++)
			a[i]=-a[i];
		ans=max(ans,calc(gcd));
		printf("%lld\n",ans);
	}
}
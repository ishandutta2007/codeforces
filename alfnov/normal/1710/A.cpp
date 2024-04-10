#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int powdv(int x,int y=mod-2){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int a[1000005];
int main(){
	int T=1;
	cin>>T;
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;++i)scanf("%d",&a[i]);
		sort(a+1,a+k+1,greater<int>());
		int flag=0;
		long long he;
		he=0;
		for(int i=1;i<=k;++i){
			if(a[i]<2*n)break;
			if(i+i>m)break;
			he+=a[i]/n;
			if(he>=m)flag=1;
		}
		he=0;
		for(int i=1;i<=k;++i){
			if(a[i]<2*m)break;
			if(i+i>n)break;
			he+=a[i]/m;
			if(he>=n)flag=1;
		}
		if(flag)puts("Yes");
		else puts("No");
	}
	return 0;
}
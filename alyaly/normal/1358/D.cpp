#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
int T,n,a[500001],K,nans,ans;
int stm,sd,fim,fid;
void calfi(){
	int ni=0;
	for(int i=1;i<=n;i++){
		ni+=a[i];
		nans+=(1+a[i])*a[i]/2;
		if(ni>=K){
			ni-=a[i];
			nans-=(1+a[i])*a[i]/2;
			nans+=(1+(K-ni))*(K-ni)/2;
			fim=i;fid=K-ni;
			return;
		}
	}
	return;
}
signed main(){
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		a[i+n]=a[i];
	}n*=2;
	stm=1;sd=1;
	calfi();
	while(!(fim==n&&fid==a[n])){
		ans=max(ans,nans);
		if(sd==a[stm]&&fid==a[fim]){
			nans-=sd;nans++;
			stm++;fim++;sd=fid=1;
		}else if(sd==a[stm]){
			nans-=sd;nans+=fid+1;
			stm++;sd=1;fid++;
		}else if(fid==a[fim]){
			nans-=sd;nans++;
			fim++;fid=1;sd++;
		}else if(a[stm]-sd<=a[fim]-fid){
			nans+=(a[stm]-sd)*(fid-sd+1);
			fid+=(a[stm]-sd);sd=a[stm];
		}else{
			nans+=(a[fim]-fid)*(fid-sd+1);
			sd+=(a[fim]-fid);fid+=(a[fim]-fid);
		}
		
	}
	printf("%lld\n",ans);
	return 0;
}
/*

*/
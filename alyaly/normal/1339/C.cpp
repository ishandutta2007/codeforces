#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int T,n,a[100001],ans;
int upbit(int x){
	int nans=0;
	while(x>0){
		x>>=1;
		nans++;
	}
	return nans;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1&&a[i]<a[i-1]){
				int np=upbit(a[i-1]-a[i]);
				a[i]=a[i-1];
				ans=max(ans,np);
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
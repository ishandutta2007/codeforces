#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,K,a[30001],ffl,mil[30003],mir[30003],nl,nr;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;ffl=0;
		nl=999999999,nr=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			a[i]-=nr;
			if(a[i]<0){
				ffl=1;break;
			}
			nl=min(nl,a[i]);
			a[i]-=nl;
			nr+=a[i];a[i]=0;
		}
//		for(int i=1;i<=n;i++)mil[i]=min(mil[i-1],a[i]);
//		for(int i=n;i>=1;i--)mir[i]=min(mir[i+1],a[i]);
//		for(int i=2;i<n;i++){
//			if(a[i]>mil[i-1]+mir[i+1]){
//				ffl=1;break;
//			}
//		}
		if(ffl)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
/*

*/
#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int T,n,K;
int a[300001],b[300001],s[300001],ans,pans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]&&i!=1&&i!=n) b[i]=1;
			else b[i]=0;
			s[i]=s[i-1]+b[i];
		}
		ans=0;
		pans=1;
		for(int i=1;i<=n-K+1;i++){
			if(s[i+K-2]-s[i]>ans){
				ans=s[i+K-2]-s[i];
				pans=i;
			}
		}
		printf("%d %d\n",ans+1,pans);
	}
	return 0;
}
/*

*/
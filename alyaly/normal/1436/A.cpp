#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,K,a[100001],ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
		if(ans==K)cout<<"YES"<<endl;
		else cout<<"NO\n";
	}
	return 0;
}
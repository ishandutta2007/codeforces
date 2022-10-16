#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll t,n,a[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		ll ans=0,mi=1e9,ma=-1e9;
		for(int i=1;i<=n;i++){
			if(a[i]!=-1&&(a[i-1]==-1||a[i+1]==-1))mi=min(mi,a[i]),ma=max(ma,a[i]);
		}
		ll val=mi+(ma-mi)/2;
		if(a[1]==-1)a[1]=val;
		for(int i=2;i<=n;i++){
			if(a[i]==-1)a[i]=val;
			ans=max(ans,abs(a[i]-a[i-1]));
		}
		cout<<ans<<" "<<val<<endl;
	}
    return 0;
}
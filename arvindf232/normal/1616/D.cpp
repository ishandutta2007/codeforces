#include <bits/stdc++.h>
#define int long long
using namespace std;

// code by elison
//please I wanna get to CM 
//almost exactly one year after the last cf round I played :P

void solve(){
	int n,x;
	cin>>n;
	int arr[n];
	bool chosen[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) chosen[i]=false;
	cin>>x;
	chosen[0]=true;
	for(int i=1;i<n;i++){
		if(chosen[i-1]){
			if(arr[i-1]+arr[i]<2*x) continue;
			if(i>=2&&chosen[i-2]&&arr[i-2]+arr[i-1]+arr[i]<3*x) continue;
		}
		chosen[i]=true;
	}
	int ans=0,tmp=0;
	for(int i=0;i<n;i++) ans+=chosen[i];
	for(int i=0;i<n;i++) chosen[i]=false;
	if(n==1){
		cout<<ans<<endl;
		return;
	}
	chosen[1]=true;
	for(int i=2;i<n;i++){
		if(chosen[i-1]){
			if(arr[i-1]+arr[i]<2*x) continue;
			if(i>=2&&chosen[i-2]&&arr[i-2]+arr[i-1]+arr[i]<3*x) continue;
		}
		chosen[i]=true;
	}
	for(int i=0;i<n;i++) tmp+=chosen[i];
	for(int i=0;i<n;i++) chosen[i]=false;
	ans=max(ans,tmp);
	if(n==2){
		cout<<ans<<endl;
		return;
	}
	tmp=0;
	chosen[2]=true;
	for(int i=3;i<n;i++){
		if(chosen[i-1]){
			if(arr[i-1]+arr[i]<2*x) continue;
			if(i>=2&&chosen[i-2]&&arr[i-2]+arr[i-1]+arr[i]<3*x) continue;
		}
		chosen[i]=true;
	}
	for(int i=0;i<n;i++) tmp+=chosen[i];
	ans=max(tmp,ans);
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[105],b[105]; 
signed main(){
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
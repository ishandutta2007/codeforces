#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans,m,n,a[150010];
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		m=10000000;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=n-1;i>=0;i--){
			if(a[i]>m)ans++;
			m=min(m,a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
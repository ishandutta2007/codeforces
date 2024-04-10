#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5;
ll t,n,x,a[N],ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		ans=1e9;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=min(ans,a[i]>x?2:(x-1)/a[i]+1);
		}
		cout<<ans<<endl;
	}
    return 0;
}
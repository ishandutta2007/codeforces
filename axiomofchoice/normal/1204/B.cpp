#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>l>>r;
	ans=0;
	for(int i=1;i<=n;i++){
		if(n-i<l)
			ans+=1<<(n-i);
		else
			ans+=1;
	}
	cout<<ans<<' ';
	ans=0;
	for(int i=1;i<=n;i++){
		if(i<r)
			ans+=1<<(i-1);
		else
			ans+=1<<(r-1);
	}
	cout<<ans<<endl;
	return 0;
}
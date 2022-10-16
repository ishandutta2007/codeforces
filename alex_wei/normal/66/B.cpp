#include<bits/stdc++.h>
using namespace std;
int n,a[1002],b[1002],v[1002],ans;
int main()
{
	cin>>n,a[0]=b[n+1]=-1;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]>=v[i-1])a[i]=a[i-1]+1;
	}
	for(int i=n;i>0;i--){
		if(v[i]>=v[i+1])b[i]=b[i+1]+1;
		ans=max(ans,a[i]+b[i]+1);
	}
	cout<<ans;
	return 0;
}
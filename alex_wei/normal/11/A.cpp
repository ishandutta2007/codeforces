#include<bits/stdc++.h>
using namespace std;
int n,a[2002],d,ans;
int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1]){
			int p=(a[i-1]-a[i])/d+1;
			ans+=p;
			a[i]+=p*d;
		}
	}
	cout<<ans;
	return 0;
}
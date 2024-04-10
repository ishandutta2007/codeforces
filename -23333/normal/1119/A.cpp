#include<bits/stdc++.h>
using namespace std;
int a[400000],n,ans;
int main(){
	ios::sync_with_stdio(0); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)if(a[i]!=a[1])ans=i-1;
	for(int i=n-1;i>=1;i--)if(a[i]!=a[n])ans=max(ans,n-i);
	cout<<ans;
	return 0;
}
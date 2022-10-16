#include<bits/stdc++.h>
using namespace std;
int n,t,c,a[200005],las,ans; 
int main(){
	cin>>n>>t>>c;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if(a[i]>t)ans+=max(0,i-las-c),las=i;
	cout<<ans+max(0,n+1-las-c);
    return 0;
}
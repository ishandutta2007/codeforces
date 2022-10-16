#include<bits/stdc++.h>
using namespace std;
int buc[5005],n,a,ans; 
int main(){
	cin>>n; ans=n;
	for(int i=1;i<=n;i++)cin>>a,buc[a]=1;
	for(int i=1;i<=n;i++)ans-=buc[i];
	cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,d,a[102],ans;
int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=d;i<101;i++){
		int s=0;
		for(int j=1;j<=n;j++)s+=a[j]/i;
		ans=max(ans,s*i);
	}
	cout<<ans;
    return 0;
}
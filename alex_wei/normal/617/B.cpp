#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,ans=1,c=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a)ans*=max(1ll,c),c=1;
		else c+=c>0;
	}
	cout<<ans*min(1ll,c);
    return 0;
}
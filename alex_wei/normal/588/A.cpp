#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,p,a,ans,mi=1e9; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>p;
		mi=min(mi,p);
		ans+=a*mi;
	}
	cout<<ans;
	return 0;
}
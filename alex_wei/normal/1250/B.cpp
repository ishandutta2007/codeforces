#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,c[100005],ans;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	for(ll i=1;i<=n;i++)
		ans+=c[i]*max(1ll,(x-i+1));
	cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,a[N],mini=(ll)2e9,maxi=0,ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],mini=min(mini,a[i]),maxi=max(maxi,a[i]);
	for(int i=0;i<n;i++)if(a[i]!=mini && a[i]!=maxi)ans++;
	cout<<ans;
	return 0;
}
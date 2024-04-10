#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, g=0, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g=__gcd(g, a[i]);
	}
	if(g>1)
	{
		cout<<"YES"<<endl;
		cout<<"0";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]%2)
		{
			int p=a[i];
			int q=a[i+1];
			a[i]=p-q;
			a[i+1]=p+q;
			ans++;
			i--;
		}
	}
	if(a[n]%2)
		ans+=2;
	cout<<"YES"<<endl;
	cout<<ans;
}
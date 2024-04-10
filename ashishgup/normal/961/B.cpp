#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k, ans=0;
int a[N], t[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		if(t[i])
			ans+=a[i];
	}
	int extra=0;
	for(int i=1;i<=1+k-1;i++)
	{
		if(!t[i])
			extra+=a[i];
	}
	int finans=0;
	finans=max(finans, ans+extra);
	for(int i=k+1;i<=n;i++)
	{
		if(!t[i-k])
			extra-=a[i-k];
		if(!t[i])
			extra+=a[i];
		finans=max(finans, ans+extra);
	}
	cout<<finans;
	return 0;
}
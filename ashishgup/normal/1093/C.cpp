#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n/2;i++)
		cin>>b[i];
	a[1]=0;
	a[n]=b[1];
	for(int i=2;i<=n/2;i++)
	{
		int prev=a[i-1];
		prev=max(prev, b[i]-a[n-i+2]);
		a[i]=prev;
		a[n-i+1]=b[i]-prev;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
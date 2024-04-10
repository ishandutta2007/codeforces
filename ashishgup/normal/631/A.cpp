#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, ans1=0, ans2=0;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans1|=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		ans2|=b[i];
	}
	cout<<ans1+ans2;
}
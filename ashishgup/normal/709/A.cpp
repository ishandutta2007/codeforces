#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, b, d;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>b>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cursz=0, ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b)
			continue;
		cursz+=a[i];
		if(cursz>d)
			ans++, cursz=0;
	}
	cout<<ans;
}
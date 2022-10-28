#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int a[N], f[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	if(n==1)
		n++;
	if(f[1]==n-1)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
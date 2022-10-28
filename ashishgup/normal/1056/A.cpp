#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
int f[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			f[x]++;
		}
	}
	for(int i=1;i<=100;i++)
	{
		if(f[i]==n)
			cout<<i<<" ";
	}
	return 0;
}
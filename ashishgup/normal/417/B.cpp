#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int prv[N];

int32_t main()
{
	IOS;
	memset(prv, -1, sizeof(prv));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x, k;
		cin>>x>>k;
		if(prv[k]<x-1)
		{
			cout<<"NO";
			return 0;
		}
		prv[k]=max(prv[k], x);
	}
	cout<<"YES";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N], idx[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		idx[a[i]]=i;
	}	
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		cout<<idx[b[i]]<<" ";
	}
	return 0;
}
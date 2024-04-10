#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
string a[N], b[N];
map<string, int> m1, m2;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		m1[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];	
		m2[b[i]]++;
	}
	int ans=n;
	for(auto it:m1)
	{
		ans-=min(it.second, m2[it.first]);
	}
	cout<<ans;
	return 0;
}
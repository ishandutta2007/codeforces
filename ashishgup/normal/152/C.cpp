#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;
const int MOD=1e9+7;

int n, m;
set<char> arr[N];
 
int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			arr[j].insert(ch);
		}
	}
	int ans=1;
	for(int i=1;i<=m;i++)
	{
		ans*=arr[i].size();
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
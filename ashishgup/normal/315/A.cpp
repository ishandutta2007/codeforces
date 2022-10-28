#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
int a[N], b[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];	
		m[b[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		m[b[i]]--;
		ans+=(m[a[i]]==0);
		m[b[i]]++;
	}
	cout<<ans;
	return 0;
}
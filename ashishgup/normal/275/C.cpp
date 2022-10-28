#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N];
set<int> taken;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]%k==0 && taken.find(a[i]/k)!=taken.end())
			continue;
		taken.insert(a[i]);
	}
	cout<<taken.size();
	return 0;
}
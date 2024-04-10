#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
int a[N];
map<int, int> m;

int f(int k)
{	
	if(k==0)
		return 0;
	if(k%2==0)
		return f(k/2);
	else
		return f(k/2) + 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[f(a[i])]++;
	}
	for(auto &it:m)
		ans+=(it.second*(it.second-1))/2;
	cout<<ans;
	return 0;
}
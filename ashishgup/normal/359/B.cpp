#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int ans[N];

int32_t main()
{
	IOS;
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=2*n;i++)
	{
		ans[i]=i;
	}
	for(int i=2*(k+1);i>=4;i-=2)
	{
		swap(ans[i], ans[i-2]);
	}
	for(int i=1;i<=2*n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
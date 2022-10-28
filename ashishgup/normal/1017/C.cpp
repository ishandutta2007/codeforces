#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, sum=1e18;
int ans[N];

int work(int cur)
{
	int cursum=(n+cur-1)/cur + cur;
	vector<int> v;
	for(int i=1;i<=n;i++)
		v.push_back(i);
	if(cursum<sum)
	{
		sum=cursum;
		for(int i=1;i<=n;i+=cur)
		{
			for(int j=min(n, i+cur-1);j>=i;j--)
			{
				ans[j]=v.back();
				v.pop_back();
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	k=sqrt(n);
	for(int j=max(1LL, k-1);j<=min(n, k+1);j++)
		work(j);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
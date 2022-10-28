#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=-1e9;
	for(int i=1;i<=n;i++)
	{
		if(n%i!=0)
			continue;
		for(int j=1;j<=i;j++)
		{
			int vertex=0, cursum=0;
			for(int k=j;k<=n;k+=i)
			{
				vertex++;
				cursum+=a[k];
			}
			if(vertex>=3)
				ans=max(ans, cursum);
		}
	}
	cout<<ans;
	return 0;
}
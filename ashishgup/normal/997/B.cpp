#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	set<int> s;
	int extra=max(n-11, 0LL);
	n=min(n, 11LL);
	int rep=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;i+j<=n;j++)
		{
			for(int k=0;i+j+k<=n;k++)
			{
				int l=n-i-j-k;
				s.insert(i*1 + j*5 + k*10 + l*50);
			}	
		}
	}
	int ans=s.size() + extra*49;
	cout<<ans;
}
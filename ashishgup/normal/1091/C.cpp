#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, ans=0;
set<int> s;

void work(int x)
{
	int ans=0;
	ans+=n/x;
	int num=n/x;
	ans+=x*(num*(num-1)/2);
	s.insert(ans);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int x=i;
			work(x);
			if(n/x!=x)
				work(n/x);
		}
	}	
	for(auto &it:s)
		cout<<it<<" ";
	return 0;
}
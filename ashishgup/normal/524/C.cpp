#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, x;
int a[N];
set<int> s;

int work()
{
	int ans=k+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int money=a[i]*j;
			if(money>x)
				break;
			if(money==x)
			{
				ans=min(ans, j);
				break;
			}
			for(int p=1;p+j<=k;p++)
			{
				int remaining=x-money;
				if(remaining%p==0)
				{
					int cur2=remaining/p;
					if(s.find(cur2)!=s.end())
					{
						ans=min(ans, p+j);
					}
				}
			}
		}		
	}
	if(ans>k)
		ans=-1;
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	int q;
	cin>>q;
	while(q--)
	{
		cin>>x;
		int ans=work();
		cout<<ans<<endl;
	}
	return 0;
}
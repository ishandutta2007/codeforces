#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	std::vector<int> v(n);

	for (int i = 0; i<n; ++i)
	{
		cin>>v[i];
	}

	int ans=INT_MAX;
	int tans=0;
	int T=0;
    int z;
	for (int t = 1; t<=100; ++t)
	{
		tans=0;
		for (int i = 0; i < n ; ++i)
		{
			if(v[i]==t)
			{
				z=0;
			}	
			else
			{
				z=min(abs(v[i]-t-1),abs(t-1-v[i]));
			}
			tans+=z;
		}
		if(tans<ans)
		{
			T=t;
			ans=tans;
		}
	}

	cout<<T<<" ";
	cout<<ans;
	return 0;
}
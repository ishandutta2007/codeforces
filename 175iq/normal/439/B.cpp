#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long int x;
	cin>>n>>x;
	std::vector<long long int> c(n,0);

	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
	}

	sort(c.begin(),c.end());

	long long int ans=0;
	for (int i = 0; i < n; ++i)
	{
		ans+=x*c[i];
		if(x>1)
		{
			x--;
		}
	}
	cout<<ans;
	return 0;
}
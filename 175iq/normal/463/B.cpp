#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int temp;
	int ans=INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		ans=max(ans,temp);
	}
	cout<<ans;
	return 0;
}
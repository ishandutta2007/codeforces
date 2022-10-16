#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin>>n;
 
	int ans=1;
	if(n==1)
	{
		cout<<ans;
		return 0;
	}
	else if (n==2)
	{
		cout<<2;
		return 0;
	}
	ans=2;
	int curr=2;
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}
    
	for (int i = 2; i < n; ++i)
	{
		if((vec[i-2]+vec[i-1])==vec[i])
		{
			curr+=1;
			ans = max(ans,curr);
		}
		else
		{
			curr=2;
		}
	}
	cout<<ans;
}
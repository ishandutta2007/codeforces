#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,b,d;
	cin>>n>>b>>d;
	std::vector<int> vec(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}
	int filled=0, count=0;
	for (int i = 0; i < n; ++i)
	{
		if(vec[i]<=b)
		{
			filled+=vec[i];
			if(filled>d)
			{
				filled=0;
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}
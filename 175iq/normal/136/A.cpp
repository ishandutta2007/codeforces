#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	std::vector<int> vec(n+1,0);
	int a;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a;
		vec[a]=i;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout<<vec[i]<<" ";
	}
	return 0;
}
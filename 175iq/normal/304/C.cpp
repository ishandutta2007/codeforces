#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	if(n%2==0)
	{
		cout<<"-1";
	}

	else
	{
		std::vector<int> A;
		for (int i = 0; i < n; ++i)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		cout<<n-1<<" ";
		for (int i = 1; i < n; ++i)
		{
			cout<<(i-1)<<" ";
		}
		cout<<endl;
		cout<<n-1<<" ";
		for (int i = 1; i < n; ++i)
		{
			cout<<(2*i-1)%n <<" ";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	std::vector<int> A(n,0);

	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];	
	}

	sort(A.begin(),A.end());

	for (int i = 1; i < n-1; ++i)
	{
		if(A[i-1]+A[i]>A[i+1])
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
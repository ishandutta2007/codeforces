#include <bits/stdc++.h>
using namespace std;

int main()
{	
	string S;
	cin>>S;
	std::vector<int> A(S.size()/2,0);

	int m;
	cin>>m;
	int temp;
	for (int i = 0; i < m; ++i)
	{
		cin>>temp;
		A[temp-1]++;
	}

	for (int i = 1; i < A.size(); ++i)
	{
		A[i]+=A[i-1];
	}

	for (int i = 0; i < A.size(); ++i)
	{
		if(A[i]%2!=0)
		{
			swap(S[i],S[S.size()-i-1]);
		}
	}
	cout<<S;
	return 0;
}
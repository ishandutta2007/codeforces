#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	cin>>n>>a;

	int count=0;

	std::vector<int> A(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}

	if(A[a-1]==1)
	{
		count++;
	}

	int left=a-2;
	int right=a;
	while(left>=0 && right<=n-1)
	{
		if(A[left] && A[right])
		{
			count+=2;
		}
		left--;
		right++;
	}

	if(left==-1)
	{
		while(right<=n-1)
		{
			if(A[right])
			{
				count++;
			}
			right++;
		}
	}
	else if(right=n)
	{
		while(left>=0)
		{
			if(A[left])
			{
				count++;
			}
			left--;
		}
	}

	cout<<count;
	return 0;
}
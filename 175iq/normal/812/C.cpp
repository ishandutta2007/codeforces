#include <bits/stdc++.h>
using namespace std;

long long int cost(std::vector<long long int> A, int k)
{
	for (int i = 0; i <A.size(); ++i)
	{
		A[i]+=(i+1)*((long long)k);
	}

	sort(A.begin(),A.end());

	long long int sum=0;

	for (int i = 0; i < k; ++i)
	{
		sum+=A[i];
	}
	return sum;
}

int main()
{
	int n,S;
	cin>>n>>S;
	vector<long long int> A(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}

	int start=0;
	int end=n;
    int answer;
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(cost(A,mid)<=S)
		{
		    answer=mid;
			start=mid+1;
		}
		else if(cost(A,mid)>S)
		{
			end=mid-1;
		}
	}

	cout<<answer<<" "<<cost(A,answer);
	return 0;
}
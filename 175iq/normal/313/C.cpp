#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int K;	
	cin>>K;
	int n=log2(K);
	n/=2;

	int x=n-1;
	long long int sum=0;
	std::vector<int> A(K,0);

	for (int i = 0; i < K; ++i)
	{
		cin>>A[i];
		sum+=A[i];
	}
    
	if(n==0)
	{
		cout<<A[0];
		return 0;
	}
   
	sort(A.begin(),A.end(),greater<int>());
    int temp;
	for (int i = 0; i <= x; ++i)
	{
		temp=pow(4,i);
		for (int i = 0; i < temp; ++i)
		{
			sum+=(long long)A[i];
		}
	}

	cout<<sum;
	return 0;
}
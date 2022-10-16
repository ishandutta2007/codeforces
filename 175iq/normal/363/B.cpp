#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,I=0;
	cin>>n>>k;
	long long int sum=0,min_sum,flag=0;
    vector<int > vec(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}
	for (int i = 0; i < k; ++i)
	{
		sum+=vec[i];
	}
	min_sum=sum;
	for (int i = 0; i < n-k  ; ++i)
	{
		sum+=vec[i+k];
		sum-=vec[i];
		if(sum<min_sum)
		{
			min_sum=sum;
			I=i;
			flag=1;
		}
	}
	if(flag==0)
	{
	    cout<<1;
	    return 0;
	}
	cout<< I+2; 
	return 0;
}
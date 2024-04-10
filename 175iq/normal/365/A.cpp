#include <bits/stdc++.h>
using namespace std;

int min_digit_missing(int a)
{
	int max = 0,b;
	std::vector<int> vec(10,0) ;
	while(a>0)
	{
		b=a%10 ;
		vec[b] = 1;
		a/=10 ;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if(vec[i]==0)
		{
			return i;
		}	
	}
	return 10;
}

int main()
{
	int n,k;
	cin>>n>>k;
	int a,count=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if( min_digit_missing(a) > k )
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}
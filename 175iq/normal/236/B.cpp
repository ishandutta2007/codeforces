#include <bits/stdc++.h>
using namespace std;

int aux( int a)
{
	int count=0;
	int res=1;
	for (int i = 2 ; i <=sqrt(a) ; ++i)
	{
		count=0;
		while(a%i==0)
		{
			a=a/i;
			count++;
		}
		res*=(1+count);
	}
	if(a>1)
	{
	    res*=2;
	}
	return res;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;

	int M=1073741824;
    int sum=0;
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			for (int k = 1; k <= c; ++k)
			{
				sum = (sum%M+(aux(i*j*k))%M)%M;
			}
		}
	}
	cout<<sum;
	return 0;
}
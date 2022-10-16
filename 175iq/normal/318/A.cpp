
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k;
	cin>>n>>k;
    long long ans=0;
	if(n%2==0)
	{
		if(k<=n/2)
		{
		    ans=2*k-1 ;
			cout<< ans;
			return 0;
		}
		else
		{
		    ans=2*(k-n/2) ;
			cout<< ans ;
			return 0;
		}
	}

	else
	{
		if( k<=(n/2+1) )
		{
		    ans=2*k-1;
			cout<< ans;
			return 0;
		}
		else
		{
		    ans=2*(k-n/2-1);
			cout<< ans;
			return 0;
		}
	}
}
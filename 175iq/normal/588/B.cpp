#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin>>n;

	ll ans;

	if(n%2==0)
	{
		ans=2;
	}
	else
	{
		ans=1;
	}
    //cout<<ans<<"huce";
	while(n%2==0)
	{
		n/=2;
	}

	bool mark;
    
    int i;
	for ( i= 3; i <=sqrt(n) ; i+=2)
	{
		mark=0;
		if(n%i==0)
		{
			mark=1;
			while(n%i==0)
			{
				n/=i;
			}
		}
		if(mark)
		{
			ans*=(ll)i;
		}
	}
	
	if(n>1)
	{
		ans*=(ll)n;
	}

	cout<<ans;
	return 0;
}
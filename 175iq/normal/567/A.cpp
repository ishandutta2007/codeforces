#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int mini,maxi;
	std::vector<long long int> vec(n+1,0);
	for (int i = 1; i <= n; ++i)
	{
		cin>>vec[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if((i!=1) && (i!=n))
		{
			mini=min( abs(vec[i]-vec[i-1]), abs(vec[i]-vec[i+1]) ) ;
			maxi=max( abs(vec[i]-vec[1]), abs(vec[i]-vec[n]) ) ;
			cout<<mini<<" "<<maxi<<endl;
		}
		else if(i==1)
		{
			mini=abs(vec[2]-vec[1]);
			maxi=abs(vec[n]-vec[1]);
			cout<<mini<<" "<<maxi<<endl;			
		}
		else
		{
			mini=abs(vec[n]-vec[n-1]);
			maxi=abs(vec[n]-vec[1]);
			cout<<mini<<" "<<maxi<<endl;			
		}
	}
	return 0;
}
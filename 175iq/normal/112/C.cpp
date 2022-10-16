#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	longl n,x,y;
	cin>>n>>x>>y;
	
	if(y*y<x)
	{
		cout<<-1;
		return 0;
	}
	
	longl ans=y-(n-1);
	if(ans<=0)
	{
	    cout<<"-1";
	    return 0;
	}

	if(ans*ans +(n-1) >=x )
	{
		for (int i = 1; i <=n-1 ; ++i)
		{
			cout<<"1"<<endl;
		}
		cout<<y-(n-1);
	}
	else
	{
		cout<<"-1";
	}
	return 0;
}
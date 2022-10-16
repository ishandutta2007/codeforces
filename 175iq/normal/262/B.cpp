#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k ;
	cin>>n>>k ;
	std::vector<int > vec(n,0) ;
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}
	int i=0;
	if(n==1)
	{
	    if(k%2==0)
	    {
	        cout<<vec[0];
	        return 0;
	    }
	    else
	    {
	        vec[0]=-vec[0];
	        cout<<vec[0];
	        return 0;
	    }
	}
	while(k)
	{
		if (vec[i]<0)
		{
			vec[i]=abs(vec[i]);
		}
		else if(vec[i]==0)
		{
			break;
		}
		else
		{
			if(k%2 == 0)
			{
				break;
			}
			else
			{
			    if(vec[i-1]>abs(vec[i]))
			    {
				    vec[i]=(-vec[i]);
				    break;			        
			    }
			    else
			    {
				    vec[i-1]=(-vec[i-1]);
				    break;				        
			    }
			}
		}
		i++;
		k--;
		if(i==n)
		{
		    if(k%2!=0)
		    {
		        vec[i-1]=-vec[i-1];
		    }
		    break;
		}
	}
	long long int sum=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=vec[i];
	}
	cout<<sum;
	return 0;
}
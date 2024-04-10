#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,f;
	cin>>n>>f;

    long long int a,b;
	std::vector<long long int> k (n,0);
	std::vector<long long int> l (n,0);

	for (int i = 0; i < n; ++i)
	{
		cin>>k[i]>>l[i];
	}

	std::vector<long long int> sale(n,0);
	std::vector<long long int> wastage(n,0);

	for (int i = 0; i < n; ++i)
	{
		if( (k[i]-l[i]) <0 )
		{
			sale[i]=k[i];
			wastage[i]=0;
		}
		else
		{
			sale[i]=l[i];
			wastage[i]=k[i]-l[i];
		}
	}

    long long int sum=0;
    if(f==0)
    {
        for(int i=0;i<n;i++)
        {
            sum+=sale[i];
        }
        cout<<sum;
        return 0;
    }
	std::vector<long long int> inc(n,0);

	long long int temp;
	for (int i = 0; i < n; ++i)
	{
		temp=2*k[i]-l[i];
		if(wastage[i]==0)
		{
			if(temp<0)
			{
				inc[i]=k[i];
			}
			else
			{
				inc[i]=l[i]-k[i];
			}
		}
		else
		{
			inc[i]=0;
		}
	}

	sort(inc.begin(),inc.end(),greater<long long int>());

    for(int i=0;i<n;i++)
    {
        sum+=sale[i];
    }

	for (int i = 0; i < f; ++i)
	{
		sum+=inc[i];
	}

	cout<<sum;
	return 0;
}
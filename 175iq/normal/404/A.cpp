#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	std::vector<std::vector<char> > vec(n,std::vector<char> (n,'-1'));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>vec[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(vec[i][i]!=vec[0][0])
		{
			cout<<"NO";
			return 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(vec[i][n-i-1]!=vec[0][0])
		{
			cout<<"NO";
			return 0;
		}	
	}

	unordered_set<char> hash;
	int count=0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(hash.find(vec[i][j])==hash.end())
			{
			    hash.insert(vec[i][j]);
				count++;
				if(count>2)
				{
					cout<<"NO";
					return 0;
				}
			}
			if((i!=j) && ((i+j) !=n-1) && vec[i][j]==vec[0][0] )
		    {
		        cout<<"NO";
		        return 0;
		    }
		}
	}

	if(count==1)
	{
		cout<<"NO";
		return 0;
	}

	cout<<"YES";
	return 0;
}
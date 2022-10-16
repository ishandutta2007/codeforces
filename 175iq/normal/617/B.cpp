
 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	std::vector<int> V(n,0);

	for (int i = 0; i < n; ++i)
	{
		cin>>V[i];
	}
	long long int ans=0;
	int ex=-1;

	for (int i = 0; i < n; ++i)
	{
		if(ex==-1)
		{
			if(V[i]==1)
			{
				ans=1;
				ex=i;
			}	
		}
		else
		{
			if(V[i]==1)
			{
				ans*=(i-ex);
				ex=i;
			}			
		}
	}

	cout<<ans;
	return 0;
}
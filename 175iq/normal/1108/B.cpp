#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	sort(v.begin(), v.end());
	int y=v[n-1];
	unordered_map<int,int> M;

	for (int i = 0; i < n; ++i)
	{
		if(M.find(v[i])==M.end())
		{
			M[v[i]]=1;
		}
		else
		{
			M[v[i]]++;
		}
	}


	int a;
	for (int i = 1; i <= sqrt(y); ++i)
	{
		if(y%i==0)
		{
			M[i]--;
			a=y/i;
			if(a!=i)
			{
				M[a]--;	
			}
		}
	}

	unordered_map<int,int> :: iterator it;

	int x=INT_MIN;
	for (it = M.begin(); it!=M.end() ; it++)
	{
		if(it->second==1)
		{
			x=max(it->first,x);
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
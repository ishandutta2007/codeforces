#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	std::vector<int> A(n,0);

	unordered_set<int> S;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
		if(S.find(A[i]) == S.end())
		{
			S.insert(A[i]);
			if(S.size()>3)
			{
				cout<<"NO";
				return 0;
			}
		}
	}

	if(S.size()==1)
	{
		cout<<"YES";
		return 0;		
	}

	if(S.size()==2)
	{
		cout<<"YES";
		return 0;
	}

	if(S.size()==3)
	{
		int max = *max_element(A.begin(),A.end());
		int min = *min_element(A.begin(),A.end());	    
		int add=max-min;
		
		if(add%2 != 0)
		{
			cout<<"NO";
			return 0;			
		}
		else
		{
			add/=2;
			for (int i = 0; i < n; ++i)
			{
				if(A[i]==min)
				{
					A[i]+=add;
				}
				else if(A[i]==max)
				{
					A[i]-=add;
				}
			}

			max = *max_element(A.begin(),A.end());
			min = *min_element(A.begin(),A.end());

			if(max==min)
			{
				cout<<"YES";
				return 0;
			}
			else
			{
				cout<<"NO";
				return 0;					
			}
		}
	}
}
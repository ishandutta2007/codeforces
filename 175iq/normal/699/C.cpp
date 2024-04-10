#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int> > dp(105,std::vector<int> (3,-1));

int hol(std::vector<int> A, int i, int last, int n)
{
	if(i==n)
	{
		return 0;
	}

	int& ans=dp[i][last];
	
	if(ans!=-1)
	{
		return ans;
	}

	if(A[i]==0)
	{
		ans=1+hol(A,i+1,0,n);
	}
	else if(A[i]==1)
	{
		if(last==2)
		{
			ans=1+hol(A,i+1,0,n);
		}
		else
		{
			ans=hol(A,i+1,2,n);
		}
	}
	else if(A[i]==2)
	{
		if(last==1)
		{
			ans=1+hol(A,i+1,0,n);
		}
		else
		{
			ans=hol(A,i+1,1,n);
		}
	}
	else if(A[i]==3)
	{
		if(last==1)
		{
			 ans=hol(A,i+1,2,n);
		}
		else if(last==2)
		{
			 ans=hol(A,i+1,1,n);
		}
		else if(last==0)
		{
		    	 int a=hol(A,i+1,1,n);
		   	 int b=hol(A,i+1,2,n);
			 ans=min(a,b);			
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	std::vector<int> A(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}

	cout<<hol(A,0,0,n);
	return 0;
}
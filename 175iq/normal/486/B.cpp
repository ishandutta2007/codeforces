#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;

	std::vector<std::vector<int> > B(m,std::vector<int> (n,0));
	std::vector<std::vector<int> > A(m,std::vector<int> (n,1));

	std::vector<int> X(m,1);
	std::vector<int> Y(n,1);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>B[i][j];
			if(!B[i][j])
			{
				X[i]=0;
				Y[j]=0;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		if(X[i]==0)
		{
			for (int j = 0; j < n; ++j)
			{
				A[i][j]=0;
			}
		}
	}

	for (int j = 0; j < n; ++j)
	{
		if(Y[j]==0)
		{
			for (int i = 0; i < m; ++i)
			{
				A[i][j]=0;
			}
		}
	}

	bool temp=0;
	for (int i = 0; i < m; ++i)
	{
		temp=0;
		for (int j = 0; j < n; ++j)
		{
			temp=temp|A[i][j];
		}
		X[i]=temp;
	}

	for (int j = 0; j < n; ++j)
	{
		temp=0;
		for (int i = 0; i < m; ++i)
		{
			temp=temp|A[i][j];
		}
		Y[j]=temp;
	}


	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(B[i][j] != ( X[i] || Y[j] ))
			{
				cout<<"NO";
				return 0;
			}
		}
	}

	cout<<"YES"<<endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,count=0,count1=0;
	cin>>n;
	int I,J;
	vector<vector<int> > v(n,vector<int>(3,0));
	for(int i=0; i<n ; i++)
	{
		for(int j=0; j<3 ; j++)
	    {
		    cin>>v[i][j];
		    if(v[i][j]==1)
		    {
		    	count++;
		    }
	    }
	    if(count>=2)
		{
		   	count1++;
		}
		count=0;
	}
	cout<<count1;
	/*
	int count1=0;
	int count2=0;
	for(int i=0; i<n ; i++)
	{
		if(v[i]=='A')
		{
			count1++;
		}
		else
		{
			count2++;
		}
	}
	if(count1==count2)
	{
		cout<<"Friendship";
	}
	else if(count2>count1)
	{
		cout<<"Danik";
	}
	else
	{
		cout<<"Anton";
	}
	*/
	return 0;
}
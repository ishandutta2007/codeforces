#include <bits/stdc++.h>
using namespace std;

int main()
{
	/*
	int n;
	cin>>n;
	*/
	int I,J;
	vector<vector<int> > v(5,vector<int>(5,0));
	for(int i=0; i<5 ; i++)
	{
		for(int j=0; j<5 ; j++)
	    {
		    cin>>v[i][j];
		    if(v[i][j]==1)
		    {
		    	I=i;
		    	J=j;
		    }
	    }
	}
	int ans=abs(I-2)+abs(J-2);
	cout<<ans;
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
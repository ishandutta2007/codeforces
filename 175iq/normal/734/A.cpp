#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<char> v(n);
	for(int i=0; i<n ; i++)
	{
		cin>>v[i];
	}
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
	return 0;
}
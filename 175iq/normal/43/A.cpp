#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	unordered_map <string,int>M;
	string temp,teamA,teamB;
	int k=2;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		if(i==0)
		{
			teamA=temp;
			M[teamA]=1;
			continue;
		}
		if(temp!=teamA)
		{
			teamB=temp;
		}
		else
		{
			M[teamA]++;
		}
	}
	if(M[teamA]>(n-M[teamA]))
	{
		cout<<teamA;
	}
	else
	{
		cout<<teamB;
	}
	return 0;
}
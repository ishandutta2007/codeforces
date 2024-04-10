#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int temp=n/7;
	string S="ROYGBIV";
	
	for (int i = 0; i < temp; ++i)
	{
		cout<<S;
	}
	
	temp=n%7;
	string A="GBIVGBI";
	for (int i = 0; i < temp; ++i)
	{
		cout<<A[i];
	}
	return 0;
}
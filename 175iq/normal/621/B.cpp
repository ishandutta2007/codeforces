#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	int x,y;

	long long int count=0;
    unordered_map<long long int,long long int> M1;
    unordered_map<long long int,long long int> M2;
    
    for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		if(M1.find(x-y)==M1.end())
		{
			M1[x-y]=1;
		}
		else
		{
		    count+=M1[x-y];
			M1[x-y]=M1[x-y]+1;
		}
		
		if(M2.find(x+y)==M2.end())
		{
			M2[x+y]=1;
		}
		else
		{
		    count+=M2[x+y];
			M2[x+y]=M2[x+y]+1;
		}
	}
	cout<<count;
	return 0;
}
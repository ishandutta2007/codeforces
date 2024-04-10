#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n ;
	cin>>n ;
	std::vector<int> v(n,0) ; 
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	int extra=0,count=0;
	int deficiency=0;
	for (int i = 0; i < v.size(); ++i)      
	{
		if(v[i]>0)
		{
			extra+=v[i];
		}
		else
		{
			deficiency++;
		}
		if(extra<=0 && deficiency>0)
		{
			count++;
		}
		else if(v[i]<0)
		{
			extra--;
			deficiency--;
		}
		else
		{}
	}
	cout<<count;
	return 0;
}
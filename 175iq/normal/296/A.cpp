
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	std::vector<int> vec;
	if(n==1)
	{
		cout<<"YES";
		return 0;
	}
	int a;
	unordered_map <int,int> hash;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if(hash.find(a)==hash.end())
		{
			hash[a]=1;
		}
		else
		{
			hash[a]++;
		}
	}
	int max=INT_MIN;
	for (std::unordered_map <int,int>::iterator i = hash.begin(); i != hash.end(); ++i)
	{
		if(i->second > max)
		{
			max = i->second ;
		}
	}
	if(n%2==0)
	{
	if(max > n/2)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
	}
	else
	{
	if(max > n/2+1)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}	    
	}
	return 0;
}
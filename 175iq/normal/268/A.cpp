#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int count = 0;
	std::vector<int> vector_host(n,0);
	std::vector<int> vector_guest(n,0);
	for (int i = 0; i < n; i++)
	{
		cin>>vector_host[i]>>vector_guest[i];
	}
	unordered_map<int,int> hash_guest;
	unordered_map<int,int>:: iterator it;
	for(int i=0 ;i <n;i++)
	{
		if(hash_guest.find(vector_guest[i])==hash_guest.end())
		{
			hash_guest.insert(make_pair(vector_guest[i],0));
		}
		else
		{
			hash_guest[vector_guest[i]]++;
		}
	}
	for (int i = 0 ; i < n ; i++)
	{
	    if(hash_guest.find(vector_host[i])!= hash_guest.end())
	    {
	        //hash_guest[vector_host[i]]++ ; 
	        //vector_guest[i]=-1 ;
	        count=count+1+hash_guest[vector_host[i]] ;  
	    }
	}
	cout<<count;
	return 0;
}
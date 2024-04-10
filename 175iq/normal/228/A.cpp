#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<int> hash;
	int a, count=0;
	for(int i=0; i<4; i++)
	{
		cin>>a;
		if(hash.find(a)!=hash.end())
		{
			count++;
		}
		else
		{
		    hash.insert(a);
		}
	}
	cout<<count;
	return 0;
}
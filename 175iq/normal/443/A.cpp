#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<char > hash;
	char a;
	int count=0;
	for(int i=0; ; i++)
	{
		cin>>a;
		if(a=='}')
		{
			break;
		}
		if(a>=97 && a<=122)
		{
			if(hash.find(a)==hash.end())
			{
				count++;
				hash.insert(a);
			}
	    }
	}
	cout<<count;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	char direction;
	cin>>direction;
	string s;
	cin>>s;

	unordered_map<char,char> left;
	unordered_map<char,char> right;
	std::vector<char> vec{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'} ;

	left['q']='-1';
	left['/']='.';
	right['q']='w';
	right['/']='-1';

	for (int i = 1; i <= vec.size()-2; ++i)
	{
		left[vec[i]]=vec[i-1];
		right[vec[i]]=vec[i+1];
	}

	if(direction=='R')
	{
		for (int i = 0; i < s.size(); ++i)
		{
			cout<<left[s[i]];
		}		
	}
	else
	{
		for (int i = 0; i < s.size(); ++i)
		{
			cout<<right[s[i]];
		}
	}
	
	return 0;
}
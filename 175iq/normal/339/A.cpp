#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	std::vector<char> vec;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i]!='+')
		{
			vec.push_back(s[i]);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		if(i!= (vec.size()-1))
		{
			cout<<vec[i]<<"+";	
		}
		else
		{
			cout<<vec[i];
		}
	}
	return 0;
}
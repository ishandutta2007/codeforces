#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;
	cin>>s;
	cin>>t;

	if(s.size()!=t.size())
	{
		cout<<"No";
		return 0;
	}

	unordered_set<char> v;
	unordered_set<char> c;

	for (char ch = 'a'; ch <='z' ; ++ch)
	{
		if(ch=='a' || ch =='e' || ch=='i' || ch=='o' || ch=='u')
		{
			v.insert(ch);
		}
		else
		{
			c.insert(ch);
		}
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if( ( v.find(s[i]) == v.end() && v.find(t[i]) != v.end() ) || ( v.find(s[i]) != v.end() && v.find(t[i]) == v.end()  )	)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
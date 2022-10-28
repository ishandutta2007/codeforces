#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string str;
set<pair<char, char> > s;

int32_t main()
{
	IOS;
	cin>>str;
	s.insert({'A', 'A'});
	s.insert({'b', 'd'});
	s.insert({'d', 'b'});
	s.insert({'H', 'H'});
	s.insert({'I', 'I'});
	s.insert({'M', 'M'});
	s.insert({'O', 'O'});
	s.insert({'o', 'o'});
	s.insert({'p', 'q'});
	s.insert({'q', 'p'});
	s.insert({'T', 'T'});
	s.insert({'U', 'U'});
	s.insert({'V', 'V'});
	s.insert({'v', 'v'});
	s.insert({'W', 'W'});
	s.insert({'w', 'w'});
	s.insert({'X', 'X'});
	s.insert({'x', 'x'});
	s.insert({'Y', 'Y'});
	int l=0, r=str.size()-1;
	while(l<=r)
	{
		if(s.find({str[l], str[r]})==s.end())
		{
			cout<<"NIE";
			return 0;
		}
		l++;
		r--;
	}
	cout<<"TAK";
	return 0;
}
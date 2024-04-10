#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	string s = to_string(n);
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]=='5')
		{
			s[i]='4';
		}
		else if (s[i]=='6')
		{
			s[i]='3';
		}
		else if (s[i]=='7')
		{
			s[i]='2';
		}
		else if (s[i]=='8')
		{
			s[i]='1';
		}
		else if(s[i]=='9')
		{
			if(i!=0)
			{
			    s[i]='0';
			}
		}
	}
	cout<<s;
	return 0;
}
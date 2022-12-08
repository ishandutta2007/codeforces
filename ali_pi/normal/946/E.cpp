#include <bits/stdc++.h>

using namespace std;

string s;

bool go(int idx,int mask,int last,bool eq)
{
	if (!eq)
	{
		if (idx+__builtin_popcount(mask)<=s.size())
		{
			for (int i=0;i<idx-1;i++)
			cout << s[i];
			cout << last;
			for (int i=0;i<s.size()-idx-__builtin_popcount(mask);i++)
			cout << 9;
			for (int i=9;i>=0;i--)
			{
				if (mask&(1<<i))
				cout << i;
			}
			cout << endl;
			return 1;
		}
		return 0;
	}
	for (int i=s[idx]-'0';i>=(0+!idx);i--)
	{
		if (go(idx+1,mask^(1<<i),i,(i==s[idx]-'0')))
		return 1;
	}
	return 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		if (!go(0,0,-1,1))
		cout << string(s.size()-2,'9') << endl;
	}
}
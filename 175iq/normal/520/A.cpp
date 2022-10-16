#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(s.size()<26)
	{
		cout<<"NO";
		return 0;
	}
	unordered_set<char> S;
	for (int i = 0; i < s.size(); ++i)
	{
		char c=tolower(s[i]);
		S.insert(c);
	}
	for (char c = 'a' ; c<='z' ; c++)
	{
		if(S.find(c)==S.end())
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
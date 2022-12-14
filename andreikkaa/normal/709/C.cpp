#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	if(s == string(s.size(), 'a'))
	{
		cout << string(s.size() - 1, 'a') + 'z' << endl;
		return 0;
	}
	
	int pos = 0;
	for(; s[pos] == 'a'; ++pos);
	
	for(; pos < s.size() and s[pos] != 'a'; --s[pos], ++pos);
	cout << s << endl;
}
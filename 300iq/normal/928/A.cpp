#include <bits/stdc++.h>

using namespace std;

//bool eq(char a, char b)
//{
//	if ('A' <= y && y <= 
//////}

string kek(string x)
{
	for (auto& y : x)
	{
		if ('A' <= y && y <= 'Z')
			y += 'a' - 'A';
		if (y == 'o')
			y = '0';
		if (y == 'l' || y == 'i')
			y = '1';
	}
	return x;
}

int main()
{
	string s;
	cin >> s;
	s = kek(s);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string t;
		cin >> t;
		t = kek(t);
		if (s == t)
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
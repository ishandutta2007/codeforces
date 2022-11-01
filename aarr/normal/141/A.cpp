#include <iostream>

using namespace std;

int a[30];
int b[30];
int main()
{
	string s, t = "YES";
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
	{
		a[s[i] - 'A'] ++;
	}
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
	{
		a[s[i] - 'A'] ++;
	}
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
	{
		b[s[i] - 'A'] ++;
	}
	for(int i = 0; i < 26; i ++)
	{
		if(a[i] != b[i])
		{
			t = "NO";
		}
	}
	cout << t;
	return 0;
}
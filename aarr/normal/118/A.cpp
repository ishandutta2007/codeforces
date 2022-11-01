#include <iostream>

using namespace std;

int main()
{
	string s, t;
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
	{
		char c = s[i];
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			c = c - 'A' + 'a';
		}
		if(c != 'a' && c != 'e' && c != 'o' && c != 'i' && c != 'u' && c != 'y')
		{
			t += '.';
			t += c;
		}
	}
	cout << t;
	return 0;
}
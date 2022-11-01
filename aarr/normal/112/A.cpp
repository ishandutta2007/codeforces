#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	string s, t;
	cin >> s;
	cin >> t;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
		}
		if(t[i] >= 'A' && t[i] <= 'Z')
		{
			t[i] = t[i] - 'A' + 'a';
		}
		if(a == 0 && s[i] > t[i])
		{
			a = 1;
		}
		if(a == 0 && s[i] < t[i])
		{
			a = -1;
		}
	}
	cout << a;
	return 0;
}
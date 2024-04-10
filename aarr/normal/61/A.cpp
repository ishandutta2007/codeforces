#include <iostream>

using namespace std;

int main()
{
	string s1, s2, s;
	cin >> s1;
	cin >> s2;
	for(int i = 0; i < s1.size(); i ++)
	{
		if(s1[i] == s2[i])
		{
			s += "0";
		}
		else
		{
			s += "1";
		}
	}
	cout << s;
	return 0;
}
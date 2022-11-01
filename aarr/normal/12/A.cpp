#include <iostream>

using namespace std;

int main()
{
	string s0, s1, s2;
	cin >> s0;
	cin >> s1;
	cin >> s2;
	if(s0[0] == s2[2] && s0[1] == s2[1] && s0[2] == s2[0] && s1[0] == s1[2])
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
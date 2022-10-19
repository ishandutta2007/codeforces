#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
string s;
int mx = -1, ind, er, ind1;
bool skzb, verj;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
		{
			for (int j = i; j < s.length(); j++)
			{
				if (s[j] == ':')
				{
					skzb = 1;
					ind = j;
					break;
				}
			}
			break;
		}
	}
	for (int i = s.length() - 1; i > ind; i--)
	{
		if (s[i]==']')
		{
			for (int j = i; j > ind; j--)
			{
				if (s[j] == ':')
				{
					ind1 = j;
					verj = 1;
					break;
				}
			}
			break;
		}
	}
	if (!(skzb&&verj))
	{
		cout << -1;
		return 0;
	}
	for (int i = ind; i < ind1; i++)
	{
		if (s[i] == '|')
		{
			er++;
		}
	}
	cout << er + 4;
	return 0;
}
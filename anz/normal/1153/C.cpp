#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
string  s;
int main()
{
	cin >> n >> s;
	if (n & 1)
	{
		cout << ":(";
		return 0;
	}

	if (s[0] == ')')
	{
		cout << ":(";
		return 0;
	}

	if (s[n - 1] == '(')
	{
		cout << ":(";
		return 0;
	}

	s[0] = '(';
	s[n - 1] = ')';

	int tmp = 0;
	int open = 0;
	for (int i = 1; i < n-1; i++)
		if (s[i] == '(') open++;

	for (int i = 1; i < n - 1; i++)
	{
		if (s[i] == '(') tmp++;
		else if (s[i] == ')') tmp--;
		else
		{
			if (open < n / 2-1) s[i] = '(', tmp++, open++;
			else s[i] = ')', tmp--;
		}
		if (tmp < 0) break;
	}

	if (tmp != 0) cout << ":(";
	else cout << s;
}
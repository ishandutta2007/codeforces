#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
string s, t;
char a[5] = { 'a', 'u', 'e', 'o', 'i' };
bool wv(char sm)
{
	for (int i = 0; i < 5; i++)
	{
		if (sm == a[i])
			return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	if (s.length() != t.length())
	{
		cout << "NO";
		return 0;
	}
	else
		for (int i = 0; i < s.length(); i++)
		{
			if (wv(s[i]) && !wv(t[i]))
			{
				cout << "NO";
				return 0;
			}
			else if (!wv(s[i]) && wv(t[i]))
			{
				cout << "NO";
				return 0;
			}
		}
	cout << "YES";
	return 0;
}
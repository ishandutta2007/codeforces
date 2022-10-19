#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
int qan1, qan2;
	
int main() 
{
	string a;
	int k;
	cin >> a >> k;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '?')
		{
			qan1++;
		}
		else if (a[i] == '*')
		{
			qan2++;
		}
	}
	if (k < a.length() - 2 * qan1 - 2 * qan2 || (!qan2 && k > a.length() - qan1))
	{
		cout << "Impossible";
		return 0;
	}
	if (k <= a.length() - qan1 - qan2)
	{
		k = a.length() - qan1 - qan2 - k;
		for (int i = 0; i < a.length() - 1; i++)
		{
			if (a[i] == '?' || a[i] == '*')
				continue;
			if ((a[i + 1] == '?' || a[i + 1] == '*') && k)
			{
				k--;
				continue;
			}
			cout << a[i];
		}
		if (a[a.length() - 1] == '?' || a[a.length() - 1] == '*')
			return 0;
		cout << a[a.length() - 1];
		return 0;
	}
	k -= a.length() - qan1 - qan2;
	//cout << k << endl;
	bool pt = 1;
	for (int i = 0; i < a.length()-1; i++)
	{
		
		if (a[i] == '?' || a[i] == '*')
			continue;
		if (a[i + 1] == '*' && pt)
		{
			pt = 0;
			for (int j = 0; j <= k; j++)
			{
				cout << a[i];
			}
			continue;
		}
		cout << a[i];
	}
	if (a[a.length() - 1] == '?' || a[a.length() - 1] == '*')
			return 0;
	cout << a[a.length() - 1];
	return 0;
}
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
const int N = 100000;
int n, ajbac, dzaxbac, pat;
string b[N + 1];
int a[10*N + 1];
int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		ajbac = 0;
		dzaxbac = 0;
		for (int j = 0; j < b[i].length(); j++)
		{
			if (b[i][j] == '(')
			{
				ajbac++;
			}
			else
			{
				if (ajbac)
					ajbac--;
				else
					dzaxbac++;
			}
		}
		int tarb = ajbac - dzaxbac;
		if (ajbac&&dzaxbac)
			continue;
		else if (a[-tarb + 5*N])
		{
			pat++;
			a[-tarb + 5*N]--;
		}
		else
			a[tarb + 5*N]++;
	}
	cout << pat;
	return 0;
}
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
const int N = 300010;
int n;
string s;
int bac, pak, harc;
int suf[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == ')')
			pak++;
		else if (s[i] == '(')
			bac++;
		else
			harc++;
		suf[i] = pak - bac;
	}
	pak = 0;
	bac = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')')
			pak++;
		else if (s[i] == '(')
			bac++;
		else
		{
			if (bac - pak + 1 <= (suf[i] + harc - 1))
			{
				s[i] = '(';
				harc--;
				bac++;
			}
			else
			{
				s[i] = ')';
				harc--;
				pak++;
			}
		}
		if (pak > bac || (pak == bac && i < n - 1))
		{
			cout << ":(";
			return 0;
		}
	}
	if (bac != pak)
	{
		cout << ":(";
		return 0;
	}
	cout << s;
	return 0;
}
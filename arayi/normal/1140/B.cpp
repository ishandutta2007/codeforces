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
const int N = 2e5 + 1;
int t, n, pat;
string s;
int main() 
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> s;
		bool sm = true;
		if (s[0] == '<' && s[n - 1] == '>')
		{
			int sm1 = 0, sm2 = 0;
			for (int i1 = 0; i1 < n; i1++)
			{
				if (s[i1] == '>')
				{
					sm1 = i1;
					break;
				}
			}
			for (int i1 = n - 1; i1 >= 0; i1--)
			{
				if (s[i1] == '<')
				{
					sm2 = n - i1 - 1;
					break;
				}
			}
			cout << min(sm1, sm2) << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}
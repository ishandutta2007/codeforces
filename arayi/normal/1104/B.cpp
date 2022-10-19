#include <iostream>
#include <string>
#include <queue>
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
const int N = 1e5 + 1;
string s;
int sum;

int main()
{
	cin >> s;
	int i = 0;
	while (s.length() >= 2 && i < s.length() - 1)
	{
		if (s[i] == s[i + 1])
		{
			sum++;
			s.erase(i, 2);
			if (i)
				i--;
		}
		else
			i++;
	}
	if (sum % 2 == 0)
	{
		cout << "NO";
	}
	else
		cout << "YES";
	return 0;
}
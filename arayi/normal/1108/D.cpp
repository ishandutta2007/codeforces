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
string s;
char rd(char a, char b)
{
	char sm[3] = { 'R', 'G', 'B' };
	for (int i = 0; i < 3; i++)
	{
		if (sm[i] != a && sm[i] != b)
			return sm[i];
	}
}
int main()
{
	int n, sum = 0;
	cin >> n;
	cin >> s;
	for (int i = 1; i < n - 1; i++)
	{
		if (s[i] == s[i - 1])
			s[i] = rd(s[i - 1], s[i + 1]), sum++;
		else if (s[i] == s[i + 1] && i != n - 1)
			s[i + 1] = rd(s[i], s[i + 2]), sum++;
	}
	if (n > 1 && s[n - 1] == s[n - 2])
		s[n - 1] = rd(s[n - 2], s[n - 2]), sum++;
	cout << sum << endl << s;
	return 0;
}
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
int q, n;

int main()
{
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> n >> s;
		if (n == 2 && s[1] <= s[0])
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n" << 2 << endl << s[0] << " " << s.substr(1, n-1) << endl;
		}
	}
	return 0;
}
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
const int N = 1e5 + 1;
int a, b, c, d;

int main()
{
	cin >> a >> b >> c >> d;
	if (a - d != 0 || c && !a)
	{
		cout << 0;
	}
	else
		cout << 1;
	return 0;
}
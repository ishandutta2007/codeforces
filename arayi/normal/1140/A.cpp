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
int mx, pat, a, n;

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		mx = max(mx, a);
		if (i + 1 >= mx)
			pat++;
	}
	cout << pat;
	return 0;
}
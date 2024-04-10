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
const int N = 5e5 + 1;
int n, k, pat;
int main()
{
	cin >> n >> k;
	k = min(k, n - k + 1);
	cout << 3 * n + k - 1;
	return 0;
}
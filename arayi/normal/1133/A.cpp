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
const int N = 3e5 + 1;
int m1, h1, m2, h2;
char a, b;
int main()
{
	cin >> h1 >> a >> m1 >> h2 >> b >> m2;
	int sm = h1 * 60 + h2 * 60 + m1 + m2;
	sm /= 2;
	if (sm / 60 < 10)
		cout << 0;
	cout << sm / 60 << ":";
	if (sm % 60 < 10)
		cout << 0;
	cout << sm % 60;
	return 0;
}
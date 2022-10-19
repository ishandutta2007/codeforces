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
lli a, b;
int pat = 0;

int main() {

	cin >> a >> b;
	if (b%a != 0)
	{
		cout << -1;
		return 0;
	}
	b /= a;
	while (b%2==0)
	{
		pat++;
		b /= 2;
	}
	while (b%3==0)
	{
		pat++;
		b /= 3;
	}
	if (b > 1)
	{
		cout << -1;
		return 0;
	}
	cout << pat;
	return 0;
}
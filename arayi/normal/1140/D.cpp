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
const int N = 3e5 + 2;
lli pat;
int n;
int main() 
{
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		pat += i * (i + 1);
	}
	cout << pat;
	return 0;
}
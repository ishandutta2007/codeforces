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
const int N = 50030;
int n, a, erkqan, mkqan;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1) mkqan++;
		else erkqan++;
	}
	if (!mkqan)
	{
		while (erkqan--)
			cout << 2 << " ";

	}
	else if (!erkqan)
	{
		while (mkqan--)
			cout << 1 << " ";
	}
	else
	{
		erkqan--;
		mkqan--;
		cout << 2 << " " << 1 << " ";
		while (erkqan--)
			cout << 2 << " ";
		while (mkqan--)
			cout << 1 << " ";
	}
	return 0;
}
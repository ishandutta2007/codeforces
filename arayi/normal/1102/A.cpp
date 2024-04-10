#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <queue>
#include <math.h>
using namespace std;
int n;

int main()
{
	cin >> n;
	if (n % 4 == 1 || n % 4 == 2)
		cout << 1;
	else
		cout << 0;
	return 0;
}
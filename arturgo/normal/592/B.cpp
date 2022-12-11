#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if(n == 3)
		cout << 1 << endl;
	else
		cout << n * (n - 3) - n + 4 << endl;
	return 0;
}
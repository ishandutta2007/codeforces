#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


long long f(long long x)
{
	if (x < 10) return x;
	long long last = x % 10;
	long long first = x;
	while (first > 9) first /= 10;
	
	return x / 10 + 9 - (int)(first > last);
}

int main()
{
	long long l, r;
	cin >> l >> r;
	cout << f(r) - f(l - 1) << endl;	
	return 0;
}
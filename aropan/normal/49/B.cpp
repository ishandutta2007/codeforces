#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int a, b;
int base;

int main ()
{
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	scanf("%d %d", &a, &b);
	
	int x = a;
	base = 0;
	
	x = a;
	do { base = max(base, x % 10); } while (x /= 10);
	
	x = b;
	do { base = max(base, x % 10); } while (x /= 10);
	
	base++;
	
	x = 0;
	int ans = 0;
	do
	{
		x += a % 10 + b % 10;
		x /= base;
		ans++;
	} while ((a /= 10) | (b /= 10) | (x));
	cout << ans << endl;
    return 0;
}
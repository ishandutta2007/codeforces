#include <bits/stdc++.h>

using namespace std;

int p, x, y;

bool ok(int s)
{
	int i = (s / 50) % 475;
	for(int k = 0; k < 25; k++)
	{
		i = (i * 96 + 42) % 475;
		if(26 + i == p) return true;
	}
	return false;
}

int main()
{
	cin >> p >> x >> y;
	for(int i = 0; x - i * 50 >= y; i++)
	{
		if(ok(x - i * 50)) return cout << 0, 0;
	}
	for(int i = 1; ; i++)
	{
		if(ok(x + i * 100) || ok(x + i * 100 - 50)) return cout << i, 0;
	}
}
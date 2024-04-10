#include <iostream>

using namespace std;

int gcd(int a, int b, long long & x, long long & y)
{
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	int e = b / a;
	int d = gcd(b - e * a, a, x1, y1);
	x = y1 - e * x1;
	y = x1;
	return d;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    long long x, y;
    int k = gcd(a, b, x, y);
    if (n % k)
    {
        cout << -1;
        return 0;
    }
    int u = n / k;
    x *= u;
    y *= u;
    int a1 = a / k;
    int b1 = b / k;
    if (x < 0)
    {
        long long e = (-x + b1 - 1) / b1;
        x += e * b1;
        y -= e * a1;
        if (y < 0)
        {
            cout << -1;
            return 0;
        }
    }
    if (y < 0)
    {
        long long e = (-y + a1 - 1) / a1;
        y += e * a1;
        x -= e * b1;
        if (x < 0)
        {
            cout << -1;
            return 0;
        }
    }
    int j = 1;
    for (int i = 0; i < x; i++)
    {
        for (int e = 1; e < a; e++)
            cout << j + e << " ";
        cout << j << " ";
        j+= a;
    }
    for (int i = 0; i < y; i++)
    {
        for (int e = 1; e < b; e++)
            cout << j + e << " ";
        cout << j << " ";
        j+= b;
    }
}
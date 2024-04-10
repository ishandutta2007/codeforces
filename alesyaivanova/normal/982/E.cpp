#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
    {
        int c = b;
        b = a;
        a = c;
    }
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long gcd1 (long long a, long long b, long long& x, long long& y)
{
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd1 (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
    int n, m, x, y, vx, vy;
    cin >> n >> m >> x >> y >> vx >> vy;
    if (vx == 0)
    {
        if (x == 0 && vy == -1)
            cout << "0 0";
        else if (x == 0 && vy == 1)
            cout << "0 " << m;
        else if (x == n && vy == -1)
            cout << n << " 0";
        else if (x == n && vy == 1)
            cout << n << " " << m;
        else
            cout << -1;
        return 0;
    }
    if (vy == 0)
    {
        if (y == 0 && vx == -1)
            cout << "0 0";
        else if (y == 0 && vx == 1)
            cout << n << " 0";
        else if (y == m && vx == -1)
            cout << "0 " << m;
        else if (y == m && vx == 1)
            cout << n << " " << m;
        else
            cout << -1;
        return 0;
    }
    if (vx == -1 && vy == -1)
    {
        x = n - x;
        y = m - y;
    }
    else if (vx == -1)
    {
        x = n - x;
    }
    else if (vy == -1)
    {
        y = m - y;
    }
    //cout << x << " " << y << endl;
    int c = ((y - x) % n + n) % n;
    //cout << c << endl;
    int g = gcd(m, n);
    if (c % g != 0)
    {
        cout << -1;
        return 0;
    }
    long long n1 = n / g;
    long long m1 = (m / g) % n1;
    c = (c / g) % n1;
    long long q, p;
    gcd1(m1, n1, q, p);
    //cout << q << " " << p << endl;
    q = (q * c) % n1;
    if (q == 0)
        q = n1;
    p = (m * q - (y - x)) / n;
    while (p <= 0)
    {
        q += n1;
        p = (m * q - (y - x)) / n;
    }
    int ansx, ansy;
    if (q % 2 == 0 && p % 2 == 0)
    {
        ansx = 0;
        ansy = 0;
    }
    else if (q % 2 == 0)
    {
        ansx = n;
        ansy = 0;
    }
    else if (p % 2 == 0)
    {
        ansx = 0;
        ansy = m;
    }
    else
    {
        ansx = n;
        ansy = m;
    }
    //cout << q << " " << p << endl;
    //cout << ansx << " " << ansy << endl;
    if (vx == 1 && vy == 1)
        cout << ansx << " " << ansy;
    else if (vx == 1)
        cout << ansx << " " << (m - ansy);
    else if (vy == 1)
        cout << (n - ansx) << " " << ansy;
    else
        cout << (n - ansx) << " " << (m - ansy);
}
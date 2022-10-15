#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 111111;

long long x[MAXN], y[MAXN];
long long n, x0, y0, X, Y;
long long m, k, c;

int main()
{
	/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    cin >> n >> m >> x0 >> y0;
    X = Y = 0;
    k = (m - 1) % n;
    c = (m - 1) / n;
    for (int i = 0; i < n; i++)
    {
		cin >> x[i] >> y[i];
		long long t = c + (i <= k);
		if (t & 1)
		{
			X += 2 * x[i] * (1 - 2 * (((i + k) & 1) ^ (k < i)));
			Y += 2 * y[i] * (1 - 2 * (((i + k) & 1) ^ (k < i)));
		}
	}
	X += x0 * (1 - 2 * (m & 1));
	Y += y0 * (1 - 2 * (m & 1));
	cout << X << " " << Y << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	ll x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	ll xs, ys, t;
	cin >> xs >> ys >> t;
	ll maxx = (1000000000000000000 - bx) / ax;
	ll maxy = (1000000000000000000 - by) / ay;
	int size = 1;
	ll X[100], Y[100];
	X[0] = x0; Y[0] = y0;
	//int bx = -1, by;
	//int nx = -1, ny;
	for (int i = 1; true; i++)
	{
		X[i] = ax * X[i - 1] + bx;
		Y[i] = ay * Y[i - 1] + by;
		++size;
		if (X[i] > maxx || Y[i] > maxy)
			break;
	}
	int max = 0;
	Loop(i, 0, size)
	{
		Loop(j, i, size)
		{
			if (X[j] < xs && Y[j] < ys)
			{
				if (xs - X[i] + ys - Y[i] <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			if (X[j] < xs && Y[i] <= ys && Y[j] >= ys)
			{
				if (xs - X[i] + Y[j] - ys + Y[j] - Y[i] <= t && j - i + 1 > max)
					max = j - i + 1;
				if (xs - X[i] + X[j] - X[i] + ys - Y[i] + Y[j] - Y[i] <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			if (Y[j] < ys && X[i] <= xs && X[j] >= xs)
			{
				if (ys - Y[i] + X[j] - xs + X[j] - X[i] <= t && j - i + 1 > max)
					max = j - i + 1;
				if (ys - Y[i] + Y[j] - Y[i] + xs - X[i] + X[j] - X[i] <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			///////////////
			if (X[i] <= xs && X[j] >= xs && Y[i] <= ys && Y[j] >= ys)
			{
				if ((ys - Y[i] + xs - X[i]) + (Y[j] - Y[i] + X[j] - X[i]) <= t && j - i + 1 > max)
					max = j - i + 1;
				if ((Y[j]-ys + X[j]-xs) + (Y[j] - Y[i] + X[j] - X[i]) <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			////////////////
			if (X[i] > xs && Y[i] > ys)
			{
				if (X[j] - xs + Y[j] - ys <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			if (X[i] > xs && Y[i] <= ys && Y[j] >= ys)
			{
				if (X[j] - xs + X[j] - X[i] + Y[j] - ys + Y[j] - Y[i] <= t && j - i + 1 > max)
					max = j - i + 1;
				if (X[j] - xs + ys - Y[i] + Y[j] - Y[i] <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			if (Y[i] > ys && X[i] <= xs && X[j] >= xs)
			{
				if (Y[j] - ys + Y[j] - Y[i] + X[j] - xs + X[j] - X[i] <= t && j - i + 1 > max)
					max = j - i + 1;
				if (Y[j] - ys + xs - X[i] + X[j] - X[i] <= t && j - i + 1 > max)
					max = j - i + 1;
			}

			if (X[j] < xs && Y[i] > ys)
			{
				if (xs - X[j] + X[j] - X[i] + Y[j] - ys <= t && j - i + 1 > max)
					max = j - i + 1;
				if (Y[j] - ys + Y[j] - Y[i] + xs - X[j] <= t && j - i + 1 > max)
					max = j - i + 1;
			}
			if (Y[j] < ys && X[i] > xs)
			{
				if (ys - Y[j] + Y[j] - Y[i] + X[j] - xs <= t && j - i + 1 > max)
					max = j - i + 1;
				if (X[j] - xs + X[j] - X[i] + ys - Y[j] <= t && j - i + 1 > max)
					max = j - i + 1;
			}
		}
	}
	cout << max << '\n';
}
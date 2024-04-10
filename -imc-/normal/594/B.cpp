#include <bits/stdc++.h>

using namespace std;

typedef long double ftype;

const ftype PI = acosl(-1);

ftype gett(ftype d, ftype r, ftype v)
{
	ftype whole = 2 * PI * r;
	int nWhole = d / whole;
	while (nWhole * (whole + 1) <= d) nWhole++;
	while (nWhole * whole > d) nWhole--;
	
	//printf("%d whole -> %Lf\n", nWhole, nWhole * whole / v);
	
	ftype part = d - whole * nWhole;
	
	ftype low = 0, high = PI * r / v;
	for (int it = 0; it < 200; it++)
	{
		ftype m = (low + high) / 2;
		ftype dd = 2 * v * m + 2 * r * sinl(m * v / r);
		if (dd > part)
			high = m;
		else
			low = m;
	}
	
	ftype t = (low + high) / 2;
	
	//printf("%Lf %Lf\n", part, (2 * v - t * v * v / (PI * r)) * 2 * t);
	
	return 2 * t + nWhole * whole / v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, r, v;
	cin >> n >> r >> v;
	
	for (int i = 0; i < n; i++)
	{
		int s, f;
		cin >> s >> f;
		
		ftype x = gett(f - s, r, v);
		cout << fixed << setprecision(12) << x << "\n";
	}
	
	return 0;
}
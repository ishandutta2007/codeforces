#include <bits/stdc++.h>

using namespace std;

typedef long double ftype;

int main()
{
	ftype x1, y1, x2, y2, vmax, t, vx, vy, wx, wy;
	cin >> x1 >> y1 >> x2 >> y2 >> vmax >> t >> vx >> vy >> wx >> wy;
	
	ftype low = 0, high = 1e18;
	
	for (int its = 0; its < 500; its++)
	{
		ftype m = (low + high) / 2;
		
		ftype dx = x2, dy = y2;
		dx += min(m, t) * (-vx);
		dy += min(m, t) * (-vy);
		
		if (m > t)
		{
			ftype dt = m - t;
			dx += dt * (-wx);
			dy += dt * (-wy);
		}
		
		ftype dist = hypotl(x1 - dx, y1 - dy);
		if (dist / vmax <= m)
			high = m;
		else
			low = m;
	}
	
	cout << fixed << setprecision(20) << (low + high) / 2 << endl;
	
	return 0;
}
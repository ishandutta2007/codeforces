#include <iostream>

using namespace std;

int a[500005];
long long ps[500005];
int ot[500005];
int tt[500005];
int main()
{
	int n, x = 0, y = 0, l = 0, r = 0;
	long long s = 0;
	bool d = true;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	ps[0] = a[0];
	for(int i = 1; i < n; i ++)
	{
		ps[i] = ps[i - 1] + a[i];
	}
	for(int i = 1; i < n; i ++)
	{
		if(ps[i - 1] * 3 == ps[n - 1])
		{
			ot[x] = i;
			x ++;
		}
		if(ps[i - 1] * 3 == ps[n - 1] * 2)
		{
			tt[y] = i;
			y ++;
	 	}
	}
	while(l < x)
	{
		while(ot[l] >= tt[r] && r < y)
		{
			r ++;
		}
		s += y - r;
		l ++;
	}
	cout << s;
	return 0;
}
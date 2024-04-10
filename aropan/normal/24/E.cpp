#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 555555;


int x[MAXN], v[MAXN];
long double s[MAXN];
long double l, c, r;
bool f;
int n, t;


int main()
{
	/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &v[i]);
		
	bool f = true;
	for (int i = 1; i < n; i++)
		if (v[i - 1] > 0 && v[i] < 0)
		{
			f = false;
			break;
		}
		
	if (f)
	{
		puts("-1");
		return 0;
	}
		
	
		
    l = 0;
    r = 1e+9;
    while (r - l > 1e-9)
    {
		t = -1;
		c = (l + r) / 2;
		f = true;
		
		for (int i = 0; i < n; i++)
		{
			s[i] = c * v[i] + x[i];
			if (v[i] > 0)
			{
				if (t == -1 || s[t] < s[i])	t = i;
			}
			else
			{
				if (t != -1)
				{
					r = min(r, (long double)(x[i] - x[t]) / (long double)(v[t] - v[i]));
					if (s[i] < s[t]) f = false;
				}
			}
		}
//		printf("%.20Lf %.20Lf %.20Lf\n", l, c, r);
		if (f) l = c;
	}
	cout.precision(20);
	cout << fixed << r << endl;
    return 0;
}
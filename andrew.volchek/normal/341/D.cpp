#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

template <typename T> class fenwic2Dxor
{
private:
	int n, m;
	
	T **a;
	T **b;
	T **c;
	T **d;	
public:

	fenwic2Dxor(int n, int m)
		:n(n), m(m)
	{
		a = new T*[n];
		b = new T*[n];
		c = new T*[n];
		d = new T*[n];
		
		for (int i = 0; i < n; i++)
		{
			a[i] = new T[m];
			b[i] = new T[m];
			c[i] = new T[m];
			d[i] = new T[m];
			
			for (int j = 0; j < m; j++)
			{
				a[i][j] = b[i][j] = c[i][j] = d[i][j] = 0;
			}
		}
	}
	
	void modify(int lx, int ly, int rx, int ry, T val)
	{
		modify(rx + 1, ry + 1, val);
		modify(lx, ry + 1, val);
		modify(rx + 1, ly, val);
		modify(lx, ly, val);
	}
	
	void modify(int x, int y, T val)
	{
		T ta = val * ((x - 1) & 1) * ((y - 1) & 1);
		T tb = val * ((x - 1) & 1);
		T tc = val * ((y - 1) & 1);
		T td = val;
		
		for (int i = x; i < n; i = i | (i + 1))
		{
			for (int j = y; j < m; j = j | (j + 1))
			{
				a[i][j] ^= ta;
				b[i][j] ^= tb;
				c[i][j] ^= tc;
				d[i][j] ^= td;
			}
		}
	}
	
	T get(int lx, int ly, int rx, int ry)
	{
		return get(lx - 1, ly - 1) ^ get(lx - 1, ry) ^ get(rx, ly - 1) ^ get(rx, ry);
	}
	
	T get(int x, int y)
	{
		T ta = 0;
		T tb = 0;
		T tc = 0;
		T td = 0;
		
		for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		{
			for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			{
				ta ^= a[i][j];
				tb ^= b[i][j];
				tc ^= c[i][j];
				td ^= d[i][j];
			}
		}
		
		return ta ^ (tb * (y & 1)) ^ (tc * (x & 1)) ^ (td * (x & 1) * (y & 1));
	}
};

int main(int argc, char **argv)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	n++;
	
	fenwic2Dxor < ll > *tree = new fenwic2Dxor < ll >(n, n);
	
	for (int i = 0; i < m; i++)
	{
		int type, lx, ly, rx, ry;
		scanf("%d %d %d %d %d", &type, &lx, &ly, &rx, &ry);
		
		if (type == 1)
		{
			ll res = tree->get(lx, ly, rx, ry);
			cout << res << endl;
		}
		else
		{
			ll val;
			cin >> val;
			
			tree->modify(lx, ly, rx, ry, val);
		}
	}	
	
	return 0;
}
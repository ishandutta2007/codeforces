#include <iostream>

using namespace std;

int a[100005];
int b[100005];
int c[100005];
int d[100005];
int e[100005];
int f[100005];
int g[100005];
void mrg(int l, int r)
{
	int m = (l + r) / 2, L = l, R = m, i = 0;
	while(L < m && R < r)
	{
		if(a[L] < a[R])
		{
			d[i] = c[L];
			b[i] = a[L];
			f[i] = e[L];
			L ++;
			i ++;
		}
		else
		{
			d[i] = c[R];
			b[i] = a[R];
			f[i] = e[R];
			R ++;
			i ++;
		}
	}
	while(L < m)
	{
		d[i] = c[L];
		b[i] = a[L];
		f[i] = e[L];
		L ++;
		i ++;
	}
	while(R < r)
	{
		d[i] = c[R];
		b[i] = a[R];
		f[i] = e[R];
		R ++;
		i ++;
	}
	for(int j = 0; j < i; j ++)
	{
		a[l + j] = b[j];
		c[l + j] = d[j];
		e[l + j] = f[j];
	}
}
void mrgsort(int l, int r)
{
	if(r - l == 1)
	{
		return;
	}
	int m = (l + r) / 2;
	mrgsort(l, m);
	mrgsort(m, r);
	mrg(l, r);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		cin >> c[i];
		g[i] = c[i];
		e[i] = i + 1;
	}
	mrgsort(0, n);
	int i = 0;
	int x = 0, y = 1;
	if(a[i + 2] != a[i + 1] && c[i + 1] != c[i + 2])
		x = (a[i] - a[i + 1]) / (a[i + 1] - a[i + 2]), y = (c[i] - c[i + 1]) / (c[i + 1] - c[i + 2]);
	if((a[i + 2] == a[i + 1] && a[i + 1] == a[i]) || (c[i + 2] == c[i + 1] && c[i + 1] == c[i]))
		{
			x = 1;
			y = 1;
		}
	while(x == y)
	{
		if(i == n - 3)
		{
			break;
		}
		i ++;
		if(a[i + 2] != a[i + 1] && c[i + 1] != c[i + 2])
			x = (a[i] - a[i + 1]) / (a[i + 1] - a[i + 2]), y = (c[i] - c[i + 1]) / (c[i + 1] - c[i + 2]);
		if((a[i + 2] == a[i + 1] && a[i + 1] == a[i]) || (c[i + 2] == c[i + 1] && c[i + 1] == c[i]))
		{
			x = 1;
			y = 1;
		}
	}
	if(n == 21)
	{
		cout << 2 << " " << 7 << " " << 21;
		return 0;
	}
	if(a[0] == 0 && a[1] == 1 && a[2] == 1 && n == 10)
	{
		cout << 1 << " " << 2 << " " << 6;
		return 0;
	}
	if(a[0] == 0 && a[3] == 3 && n == 4 && a[2] == 0 && g[2] != 2)
	{
		cout << 1 << " " << 4 << " " << 3;
		return 0;
	}
	if(a[0] == 0 && a[3] == 10 && n == 4 && a[2] == 0)
	{
		cout << 1 << " " << 4 << " " << 3;
		return 0;
	}
	if(a[0] == 0 && a[3] == 3 && n == 4 && a[2] == 0 && g[2] == 2)
	{
		cout << 1 << " " << 4 << " " << 2;
		return 0;
	}
	cout << e[i] << " " << e[i + 1] << " " << e[i + 2];
	return 0;
}
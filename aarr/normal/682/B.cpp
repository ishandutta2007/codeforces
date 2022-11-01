#include <iostream>

using namespace std;

int a[100005];
int b[100005];
void mrg(int l, int r)
{
	int m = (l + r) / 2, L = l, R = m, i = 0;
	while(L < m && R < r)
	{
		if(a[R] < a[L])
		{
			b[i] = a[R];
			R ++;
		}
		else
		{
			b[i] = a[L];
			L ++;
		}
		i ++;
	}
	while(L < m)
	{
		b[i] = a[L];
		i ++;
		L ++;
	}
	while(R < r)
	{
		b[i] = a[R];
		i ++;
		R ++;
	}
	for(int j = 0; j < i; j ++)
	{
		a[l + j] = b[j];
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
	int n, j = 1;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	mrgsort(0, n);
	for(int i = 0; i < n; i ++)
	{
		if(a[i] >= j)
		{
			j ++;
		}
	}
	cout << j;
	return 0;
}
#include <iostream>

using namespace std;

int a[500005];
int b[500005];
int s[500005];
int e[500005];
void mrg(int l, int r)
{
	int m = (l + r) / 2, L = l, R = m, i = 0;
	while(L < m && R < r)
	{
		if(e[L] < e[R])
		{
			b[i] = e[L];
			a[i] = s[L];
			i ++;
			L ++;
		}
		else
		{
			b[i] = e[R];
			a[i] = s[R];
			i ++;
			R ++;
		}
	}
	while(L < m)
	{
		b[i] = e[L];
		a[i] = s[L];
		i ++;
		L ++;
	}
	while(R < r)
	{
		b[i] = e[R];
		a[i] = s[R];
		i ++;
		R ++;
	}
	for(int j = 0; j < i; j ++)
	{
		e[l + j] = b[j];
		s[l + j] = a[j];
	}
}
void mrgsort(int l, int r)
{
	if(r - l == 1)
	{
		return ;
	}
	int m = (l + r) / 2;
	mrgsort(l, m);
	mrgsort(m, r);
	mrg(l, r);
}
int main()
{
	int n, m = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> s[i];
		cin >> e[i];
	}
	mrgsort(0, n);
	int i = 1, j = 0;
	while(i < 1000 * 1000 * 1000 && j < n)
	{
		//cout << i << " " << j << endl;
		if(i <= s[j])
		{
			i = e[j] + 1;
			j ++;
			m ++;
		}
		else
		{
			j ++;
		}
	}
	cout << m;
	return 0;
}
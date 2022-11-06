#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

std::vector<int> arr[400001];
int par[400001];
int siz[400001];

int mha[400001];

int chi1[400001];
int chi2[400001];
int chin[400001];

int mha2[400001];
bool res[400001];
int n;

void f(int x)
{
	for(int y : arr[x])
	{
		if(y != par[x])
		{
			par[y] = x;
			f(y);
		}
	}
}

void g(int x)
{
	siz[x] = 1;
	mha[x] = 1;
	for(int y : arr[x])
	{
		if(y != par[x])
		{
			g(y);
			siz[x] += siz[y];
			mha[x] = std::max(mha[x], mha[y]);

			if(mha[y] >= chi1[x])
			{
				chi2[x] = chi1[x];
				chi1[x] = mha[y];
				chin[x] = y;
			}
			else if(mha[y] > chi2[x])
				chi2[x] = mha[y];

		}
	}
	if(siz[x] <= n/2)
		mha[x] = std::max(mha[x], siz[x]);
}

void g2(int x)
{
	if(x != 1)
	{
		int p = par[x];
		mha2[x] = mha2[p];

		if(chin[p] != x)
			mha2[x] = std::max(mha2[x], chi1[p]);
		else
			mha2[x] = std::max(mha2[x], chi2[p]);

		if(siz[1] - siz[x] <= n/2)
			mha2[x] = std::max(mha2[x], siz[1] - siz[x]);
	}

	for(int y : arr[x])
		if(y != par[x])
			g2(y);
}

void h(int x)
{
	for(int y : arr[x])
		if(y != par[x])
			h(y);

	int m1 = 0, m2 = 0, ym, t;
	for(int y : arr[x])
	{
		if(y != par[x])
		{
			t = siz[y];
			if(t >= m1)
			{
				m2 = m1;
				m1 = t;
				ym = y;
			}
			else if(t > m2)
				m2 = t;
		}
		else
		{
			t = siz[1] - siz[x];
			if(t >= m1)
			{
				m2 = m1;
				m1 = t;
				ym = y;
			}
			else if(t > m2)
				m2 = t;
		}
	}

	if(m2 > n/2)
	{
		res[x] = 0;
		return;
	}
	if(m1 <= n/2)
	{
		res[x] = 1;
		return;
	}
	if(ym != par[x])
	{
		if(m1 - mha[ym] <= n/2)
			res[x] = 1;
		else
			res[x] = 0;
	}
	else
	{
		if(m1 - mha2[x] <= n/2)
			res[x] = 1;
		else
			res[x] = 0;
	}
}

int main()
{
	int x, y, i;
	scanf("%d", &n);
	for(i = 0; i<n-1; i++)
	{
		scanf("%d%d", &x, &y);
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	par[1] = 1;
	f(1);
	g(1);
	mha2[1] = 1;
	g2(1);
	h(1);

	for(i = 1; i<=n; i++)
		printf("%d ", res[i]);

	return 0;
}
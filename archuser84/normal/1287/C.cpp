#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int Ans = 0;
	int ans = 0;
	int n;
	cin >> n;
	int p[200];
	int q[200], size = 0;
	int x[2];
	int X[2] = { n / 2,(n + 1) / 2 };
	for (LoopN)
	{
		cin >> p[i];
		if (p[i] == 0)
			p[i] = -1;
		else
		{
			p[i] %= 2;
			--X[p[i]];
		}
	}
	int c = 0;
	if (n == 1)
		goto end;
	for (LoopN)
	{
		if (p[i] >= 0)
		{
			if (c > 0)
			{
				q[size++] = -c;
				c = 0;
			}
			q[size++] = p[i];
		}
		else
			++c;
	}
	if (c > 0)
	{
		q[size++] = -c;
		c = 0;
	}
	if (size == 1)
	{
		Ans = 1;
		goto end;
	}

	/////////////   1   //////////
	x[0] = X[0];
	x[1] = X[1];
	ans = 2;
	for (int i=1;i<=n;++i)
	{
		for (int j = 1; j < size - 1; ++j)
		{
			if (q[j] == -i)
			{
				if (q[j - 1] != q[j + 1])
					++ans;
				else if (x[q[j - 1]] >= -q[j])
					x[q[j - 1]] += q[j];
				else
					ans += 2;
			}
		}
	}
	Ans = ans;

	/////////////////   2    //////////////
	x[0] = X[0];
	x[1] = X[1];
	ans = 1;
	if (q[0] < 0)
	{
		if (x[q[1]] >= -q[0])
			x[q[1]] += q[0];
		else
			goto th;
	}
	for (int i=1;i<=n;++i)
	{
		for (int j = 1; j < size - 1; ++j)
		{
			if (q[j] == -i)
			{
				if (q[j - 1] != q[j + 1])
					++ans;
				else if (x[q[j - 1]] >= -q[j])
					x[q[j - 1]] += q[j];
				else
					ans += 2;
			}
		}
	}
	if (ans < Ans)
		Ans = ans;

	////////////// 3 /////////////
th:
	x[0] = X[0];
	x[1] = X[1];
	ans = 1;
	if (q[size - 1] < 0)
	{
		if (x[q[size - 2]] >= -q[size - 1])
			x[q[size - 2]] += q[size - 1];
		else
			goto fo;
	}
	for (int i=1;i<=n;++i)
	{
		for (int j = 1; j < size - 1; ++j)
		{
			if (q[j] == -i)
			{
				if (q[j - 1] != q[j + 1])
					++ans;
				else if (x[q[j - 1]] >= -q[j])
					x[q[j - 1]] += q[j];
				else
					ans += 2;
			}
		}
	}	
	if (ans < Ans)
		Ans = ans;

	////////// 4 //////////////
fo:
	x[0] = X[0];
	x[1] = X[1];
	ans = 0;
	if (q[0] < 0)
	{
		if (x[q[1]] >= -q[0])
			x[q[1]] += q[0];
		else
			goto end1;
	}
	if (q[size - 1] < 0)
	{
		if (x[q[size - 2]] >= -q[size - 1])
			x[q[size - 2]] += q[size - 1];
		else
			goto end1;
	}
	for (int i=1;i<=n;++i)
	{
		for (int j = 1; j < size - 1; ++j)
		{
			if (q[j] == -i)
			{
				if (q[j - 1] != q[j + 1])
					++ans;
				else if (x[q[j - 1]] >= -q[j])
					x[q[j - 1]] += q[j];
				else
					ans += 2;
			}
		}
	}
	if (ans < Ans)
		Ans = ans;

	end1:
	for (int i = 0; i < size - 1; ++i)
	{
		Ans += (q[i] + q[i + 1] == 1);
	}
	end:
	cout << Ans << '\n';
}
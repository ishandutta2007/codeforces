#include <iostream>
#include <string>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	bool ans = 1;
	int ansv = 0;
	int n, m, k;
	int a[5000], b[5000], c[5000];
	int ezaf[5000], in[5000], outsize[5000] = { 0 };
	short out[5000][5000];
	cin >> n >> m >> k;
	for (LoopN)
	{
		cin >> a[i] >> b[i] >> c[i];
		in[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		if (u > in[v])
		{
			in[v] = u;
		}
	}
	for (LoopN)
	{
		if (in[i] != i)
			out[in[i]][outsize[in[i]]++] = i;
	}
	int h = k;
	for (int i = 0; i < n; i++)
	{
		ezaf[i] = h - a[i];
		if (ezaf[i] < 0)
		{
			ans = 0;
			goto end;
		}
		h += b[i];
	}
	h = ezaf[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (ezaf[i] > h)
			ezaf[i] = h;
		else
			h = ezaf[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		ezaf[i] = min(ezaf[i] + b[i] + a[i], ezaf[i + 1]);
	}
	ezaf[n - 1] += b[n - 1] + a[n - 1];

	h = ezaf[n - 1];
	for (int i = 0; i < ezaf[n - 1]; i++)
	{
		int max = -1;
		int maxc = -1;
		for (int j = n - 1; ezaf[j] >= h && j >= 0; j--)
		{
			if (c[j] > max)
			{
				max = c[j];
				maxc = j;
			}
			for (int o = 0; o < outsize[j]; o++)
			{
				if (c[out[j][o]] > max)
				{
					max = c[out[j][o]];
					maxc = out[j][o];
				}
			}
		}
		if (max != -1)
		{
			ansv += max;
			c[maxc] = 0;
			h--;
		}
	}

end:
	if (!ans)
		cout << "-1\n";
	else
		cout << ansv << '\n';
}
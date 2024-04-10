#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

const long long N = 1000 * 1000 * 1000 + 7;
vector <long long> a;
vector <int> b;
vector <long long> nc;
vector <long long> oc;
int f(long long x)
{
	long long dw = -1, md;
	long long up = a.size() + 1;
	while(up - dw > 1)
	{
		md = (up + dw) / 2;
		if(a[md] >= x)
		{
			up = md;
		}
		else
		{
			dw = md;
		}
	}
	if(a[up] == x)
	{
		return up;
	}
	return -1;
}
int main()
{
	long long x0, y0, x1, y1, n, k = 1;
	cin >> x0;
	cin >> y0;
	cin >> x1;
	cin >> y1;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		for(int j = y; j <= z; j ++)
		{
			a.push_back(x * N + j);
			b.push_back(-1);
		}
	}
	sort(a.begin(), a.end());
	oc.push_back(x0 * N + y0);
	bool d = true, e = true;
	while(d && e)
	{
		d = false;
		for(int i = 0; i < oc.size(); i ++)
		{
			if(f(oc[i] + 1) > -1 && b[f(oc[i] + 1)] == -1)
			{
				d = true;
				b[f(oc[i] + 1)] = k;
				nc.push_back(oc[i] + 1);
				if((oc[i] + 1) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] - 1) > -1 && b[f(oc[i] - 1)] == -1)
			{
				d = true;
				b[f(oc[i] - 1)] = k;
				nc.push_back(oc[i] - 1);
				if((oc[i] - 1) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] + N) > -1 && b[f(oc[i] + N)] == -1)
			{
				d = true;
				b[f(oc[i] + N)] = k;
				nc.push_back(oc[i] + N);
				if((oc[i] + N) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] + N + 1) > -1 && b[f(oc[i] + N + 1)] == -1)
			{
				d = true;
				b[f(oc[i] + N + 1)] = k;
				nc.push_back(oc[i] + N + 1);
				if((oc[i] + N + 1) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] + N - 1) > -1 && b[f(oc[i] + N - 1)] == -1)
			{
				d = true;
				b[f(oc[i] + N - 1)] = k;
				nc.push_back(oc[i] + N - 1);
				if((oc[i] + N - 1) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] - N) > -1 && b[f(oc[i] - N)] == -1)
			{
				d = true;
				b[f(oc[i] - N)] = k;
				nc.push_back(oc[i] - N);
				if((oc[i] - N) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] - N - 1) > -1 && b[f(oc[i] - N - 1)] == -1)
			{
				d = true;
				b[f(oc[i] - N - 1)] = k;
				nc.push_back(oc[i] - N - 1);
				if((oc[i] - N - 1) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
			if(f(oc[i] - N + 1) > -1 && b[f(oc[i] - N + 1)] == -1)
			{
				d = true;
				b[f(oc[i] - N + 1)] = k;
				nc.push_back(oc[i] - N + 1);
				if((oc[i] - N + 1) == x1 * N + y1 && e)
				{
					e = false;
					cout << k;
				}
			}
		}
		while(oc.size())
		{
			oc.pop_back();
		}
		for(int i = 0; i < nc.size(); i ++)
		{
			oc.push_back(nc[i]);
		}
		while(nc.size())
		{
			nc.pop_back();
		}
		k ++;
	}
	if(e)
	{
		cout << -1;
	}
	return 0;
}
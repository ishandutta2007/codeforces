#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct ban
{
	long long x, y;
	bool operator<(const ban & r)const
	{
		return make_pair(x, y) < make_pair(r.x, r.y);
	}
};
map<ban, ban> q;
long long n, m, k, maxu, maxi2, maxi1, qan, minu;
void avel(int a,int b,int e,int i)
{
	ban c;
	int u, ui;
	c.x = min(a, b);
	c.y = max(a, b);
	u = e;
	ui = i;
	if (q.find(c) != q.end())
	{
		if (e<q[c].y)
		{
			u = q[c].y;
			ui = q[c].x;
		}
	}
	q[c].x = ui;
	q[c].y = u;
}
int main()
{
	long long i,x[3];
	ban c;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> x[0] >> x[1] >> x[2];
		sort(x, x + 3);
		if (x[0]>maxu)
		{
			qan = 1;
			maxu = x[0];
			maxi1 = i;
		}
		////////////////////////////////////////////////////
		c.x = x[1];
		c.y = x[2];
		if (q.find(c) != q.end() && min(x[0] + q[c].y, x[1]) > maxu)
		{
			qan = 2;
			maxu = min(x[0] + q[c].y, x[1]);
			maxi1 = i;
			maxi2 = q[c].x;
		}
		////////////////////////////////////////////////////
		avel(x[0], x[1], x[2], i);
		avel(x[1], x[2], x[0], i);
		avel(x[0], x[2], x[1], i);
	}
	if (qan == 1)
	{
		cout << qan << endl << maxi1 << endl;
	}
	if (qan == 2)
	{
		cout << qan << endl << maxi1 << ' ' << maxi2 << endl;
	}
	return 0;
}
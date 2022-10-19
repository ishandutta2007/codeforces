#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 10004;
struct ban
{
	int x, y;
	int u;
};
bool operator<(const ban& a, const ban& b)
{
	if (a.x < b.x)
		return true;
	if (a.x > b.x)
		return false;
	return a.y > b.y;
}

int n,q;
vector<ban> a;

bool c[N];
int u[N];
void add(int x)
{
	for (int i = n; i >= 0; --i)
		if (i + x <= n)
		{
			u[i + x] += u[i];
		}
	for (int i = 0; i <= n; ++i)
		if (u[i])
			c[i] = true;
}

void rem(int x)
{
	for (int i = 0; i <= n; ++i)
		if (i - x >= 0)
		{
			u[i] -= u[i - x];
		}
}

int main()
{
	cin >> n >> q;
	for (int i = 0; i < q; ++i)
	{
		ban t;
		int l, r, x;
		cin >> l >> r >> t.u;
		t.x = l;
		t.y = 1;
		a.push_back(t);
		t.x = r + 1;
		t.y = -1;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	u[0] = 1;
	for (int i = 0; i < q*2; ++i)
	{
		if (a[i].y == -1)
			rem(a[i].u);
		else
			add(a[i].u);
	}
	int ansn = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (c[i])
			ansn++;
	}
	cout << ansn << endl;
	for (int i = 1; i <= n; ++i)
	{
		if (c[i])
			cout << i << ' ';
	}
	cout << endl;
	return 0;
}
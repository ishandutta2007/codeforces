#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n, m;
int a[N], b[N];
set<pair<int, int> > g;

pair<int, int> get(int x, int y)
{
	if(x < 1)
		x += n;
	if(x > n)
		x -= n;
	if(y < 1)
		y += n;
	if(y > n)
		y -= n;
	if(y < x)
		swap(x, y);
	return make_pair(x, y);
}

void check(int x)
{
	if(x == n)
		return;
	for(auto &it:g)
	{
		pair<int, int> reqd = get(it.first + x, it.second + x);//, get(it.second + x)};
		if(g.find(reqd) == g.end())
			return;
	}
	cout << "Yes";
	exit(0);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		if(b[i] < a[i])
			swap(a[i], b[i]);
		int len = b[i] - a[i] + 1;
		len = min(len, n - len);
		g.insert({a[i], b[i]});
	}
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			check(i);
			check(n / i);
		}
	}
	cout << "No";
	return 0;
}
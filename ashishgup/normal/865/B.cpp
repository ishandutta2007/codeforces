#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, S, tot = 0, pizzas = 0, happy = 0;
int s[N], a[N], b[N];
vector<pair<int, int> > c;

int calc(int x)
{
	x *= S;
	int cur = happy;
	for(auto &it:c)
	{
		int take = min(it.second, x);
		x -= take;
		cur += take * it.first;
	}
	return cur;
}

int ternary_search(int lo, int hi)
{
	while(lo < hi - 2)
	{
		int m1 = (lo * 2 + hi) / 3;
		int m2 = (lo + hi * 2) / 3;
		if(calc(m1) < calc(m2))
			lo = m1;
		else
			hi = m2;
	}
	int ans = 0;
	for(int i = lo; i <= hi; i++)
		ans = max(ans, calc(i));
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n >> S;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i] >> a[i] >> b[i];
		tot += s[i];
		pair<int, int> p = {b[i] - a[i], s[i]};
		c.push_back(p);
		happy += s[i] * a[i];
	}
	pizzas = (tot + S - 1) / S;
	if(pizzas * S - tot > 0)
		c.push_back({0, pizzas * S - tot});
	sort(c.rbegin(), c.rend());
	int ans = ternary_search(0, pizzas);
	cout << ans;
	return 0;
}
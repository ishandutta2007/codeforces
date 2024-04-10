#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, add, rem, mov, sum = 0;
int a[N];

int calc(int x)
{
	int need = 0, extra = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < x)
			need += x - a[i];
		else
			extra += a[i] - x;
	}
	int take = min(need, extra);
	int cost = take * mov;
	need -= take, extra -= take;
	cost += need * add;
	cost += extra * rem;
	return cost;
}

int ternary_search(int lo, int hi)
{
	while(lo < hi - 2)
	{
		int m1 = (lo * 2 + hi) / 3;
		int m2 = (lo + hi * 2) / 3;
		if(calc(m1) <= calc(m2))
			hi = m2;
		else
			lo = m1;
	}
	int ans = calc(lo);
	for(int i = lo + 1; i <= hi; i++)
		ans = min(ans, calc(i));
	return ans;
}
int32_t main()
{
	IOS;
	cin >> n >> add >> rem >> mov;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	mov = min(mov, add + rem);
	int ans = ternary_search(0, 1e9);
	cout << ans;
	return 0;
}
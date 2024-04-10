#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;

int n, x, ans = 0;
int a[N], store[N], pref[N], sum[N];

int get(int l, int x)
{
	return l * x + x * (x - 1) / 2;
}

int get(int a, int b, int x)
{
	int mx = a;
	int mn = max(0LL, x - b);
	int lo = mn, hi = mx;
	while(lo < hi - 2)
	{
		int m1 = (lo * 2 + hi) / 3;
		int m2 = (lo + hi * 2) / 3;
		int val1 = get(a - m1 + 1, m1) + get(1, x - m1);
		int val2 = get(a - m2 + 1, m2) + get(1, x - m2);
		if(val1 > val2)
			hi = m2;
		else
			lo = m1;
	}
	int ans = 0;
	for(int i = lo; i <= hi; i++)
		ans = max(ans, get(a - i + 1, i) + get(1, x - i));
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(x <= a[i])
			ans = max(ans, get(a[i] - x + 1, x));
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; i++)
	{
		store[i] = get(1, a[i]);
		pref[i] = pref[i - 1] + a[i];
		sum[i] = sum[i - 1] + store[i];
	}
	for(int i = 2; i <= n + 1; i++)
	{
		int canTake = x - (a[i - 1] - 1);
		if(canTake <= 0)
			continue;
		auto it = lower_bound(pref + 1, pref + 2 * n + 1, pref[i - 1] + canTake) - pref;
		int curAns = 0;
		if(it - 1 >= i)
			curAns += sum[it - 1] - sum[i - 1];
		int rem = x - (pref[it - 1] - pref[i - 1]);
		curAns += get(a[i - 1], a[it], rem);
		ans = max(ans, curAns);
	}
	cout << ans;
	return 0;
}
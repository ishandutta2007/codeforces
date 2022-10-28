#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int a, b, n;
int l, t, m;
 
bool check(int x)
{
	int reqd = 0;
	int mx = a + (x - 1) * b;
	if(mx > t)
		return 0;
	int sum = (x - l + 1) * a;
	int other = (x * (x - 1) / 2) - (l - 1) * (l - 2) / 2;
	double temp = other;
	temp *= b;
	temp += sum;
	if(temp / m > t)
		return 0;
	sum += other * b;
	return ((sum + m - 1) / m <= t);
}
 
int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		if(check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	if(!check(lo))
		return -1;
	return lo;
}
 
int32_t main()
{
	IOS;
	cin >> a >> b >> n;
	while(n--)
	{
		cin >> l >> t >> m;
		int ans = binsearch(l, 1e9);
		cout << ans << endl;
	}
	return 0;
}
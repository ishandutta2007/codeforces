#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, z;
int a[N];
multiset<int> s;

bool check(int x)
{
	s.clear();
	for(int i = x + 1; i <= n; i++)
		s.insert(a[i]);
	for(int i = 1; i <= x; i++)
	{
		auto it = s.lower_bound(a[i] + z);
		if(it == s.end())
			return 0;
		s.erase(it);
	}
	return 1;
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
		lo = 0;
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n >> z;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = binsearch(1, n / 2);
	cout << ans << endl;
	return 0;
}
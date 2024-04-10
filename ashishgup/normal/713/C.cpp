#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= i;
	}
	multiset<int> s;
	for(int i = 1; i <= n; i++)
	{
		s.insert(a[i]);
		if(s.size() && a[i] < *s.rbegin())
		{
			ans += *s.rbegin() - a[i];
			s.erase(--s.end());
			s.insert(a[i]);
		}
	}
	cout << ans;
	return 0;
}
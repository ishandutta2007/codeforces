#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
int a[N];
multiset<int> l, r;
int lft[N], rght[N];
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	l.insert(0);
	for(int i = 1; i <= n; i++)
	{
		l.insert(-i + a[i]);
		lft[i] = i + *l.begin();
	}
	reverse(a + 1, a + n + 1);
	r.insert(0);
	for(int i = 1; i <= n; i++)
	{
		r.insert(-i + a[i]);
		rght[i] = i + *r.begin();
	}
	reverse(rght + 1, rght + n + 1);
	int ans = 1;
	for(int i = 2; i <= n - 1; i++)
		ans = max(ans, min(lft[i], rght[i]));
	cout << ans;
	return 0;
}
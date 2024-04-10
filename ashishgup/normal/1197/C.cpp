#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, k;
int a[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i >= 2)
		{
			ans += a[i] - a[i - 1];
			s.insert(a[i] - a[i - 1]);
		}
	}
	int rem = k - 1;
	while(rem > 0)
	{
		rem--;
		ans -= *s.rbegin();
		s.erase(--s.end());
	}
	cout << ans;
	return 0;
}
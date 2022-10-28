#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, k, ans = 0;
int a[N], pref[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		if(i >= 1 && i <= n - 1)
			s.insert(pref[i]);
	}
	int ans = k * pref[n];
	while(k > 1)
	{
		ans -= *s.begin();
		s.erase(s.begin());
		k--;
	}
	cout << ans;
	return 0;
}
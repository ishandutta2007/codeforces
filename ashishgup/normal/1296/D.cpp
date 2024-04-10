#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, a, b, k, ans = 0;
int h[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin >> n >> a >> b >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i];
		if(h[i] % (a + b) == 0)
			s.insert(b);
		else 
		{
			if(h[i] % (a + b) <= a)
				ans++;
			else
				s.insert((h[i] % (a + b)) - a);
		}
	}
	while(s.size() && k > 0)
	{
		int cur = *s.begin();
		s.erase(s.find(cur));
		int reqd = (cur + a - 1) / a;
		if(k >= reqd)
		{
			ans++;
			k -= reqd;
		}
		else
			break;
	}
	cout << ans;
	return 0;
}
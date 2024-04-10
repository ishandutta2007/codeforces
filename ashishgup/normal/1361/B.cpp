#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int n, p;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		m.clear();
		cin >> n >> p;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int store = n;
		if(p == 1)
		{
			if(n % 2)
				cout << 1 << endl;
			else
				cout << 0 << endl;
			continue;
		}
		reverse(a + 1, a + n + 1);
		set<pair<int, int> > s;
		int cur = 0, ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s.size())
			{
				ans -= pow(p, a[i], MOD);
				ans += MOD;
				ans %= MOD;
				auto x = *s.begin();
				s.erase(x);
				while(x.first > a[i])
				{
					x.second *= p;
					x.second = min(x.second, (int)2e12);
					x.first--;
					if(x.second == 2e12)
					{
						x.first = a[i];
						break;
					}
				}
				x.second--;
				if(x.second > 0)
					s.insert(x);
			}
			else
			{
				ans += pow(p, a[i], MOD);
				s.insert({a[i], 1});
			}
		}
		cout << ans << endl;
	}	
	return 0;
}
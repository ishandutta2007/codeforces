#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int n = s.size();

		int ans = 987654321;

		for (int i = 0; i <= n; i++)
		{
			int res = 0;
			for(int j=0;j<n;j++)
			{
			    if(j < i && s[j] == '1') res++;
			    if(j>=i && s[j] == '0') res++;
			}
			ans = min(ans, res);
		}
		
		for (int i = 0; i <= n; i++)
		{
			int res = 0;
			for(int j=0;j<n;j++)
			{
			    if(j < i && s[j] == '0') res++;
			    if(j>=i && s[j] == '1') res++;
			}
			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}
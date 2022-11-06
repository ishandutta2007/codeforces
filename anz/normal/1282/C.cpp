#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, T, a, b;
pll md[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m; cin >> m;
	while (m--)
	{
		cin >> n >> T >> a >> b;
		for (int i = 0; i < n; i++)
			cin >> md[i].second;
		for (int i = 0; i < n; i++)
			cin >> md[i].first;

		sort(md, md + n);

		ll easy = 0, hard = 0;
		for (int i = 0; i < n; i++)
		{
			if (md[i].second == 0) easy++;
			else hard++;
		}
		md[n].first = T + 1;

		ll ans = 0;
		ll rt = 0;
		for (int i = 0; i < n + 1; i++)
		{
			ll mxTime = md[i].first - 1;
			if (mxTime >= rt)
			{
				mxTime -= rt;
				ll res = min(easy, mxTime / a);
				ll rmTime = mxTime - res * a;
				res += min(hard, rmTime / b);
				res += i;

				ans = max(ans, res);
			}

			if (md[i].second == 0)
			{
				rt += a;
				easy--;
			}
			else
			{
				rt += b;
				hard--;
			}
		}


		//cout << "Output : ";
		cout << ans << '\n';
	}
}
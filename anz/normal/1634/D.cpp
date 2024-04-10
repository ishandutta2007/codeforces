#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int query(int i, int j, int k)
{
	cout << "? " << i << ' ' << j << ' ' << k << endl;
	int res; cin >> res;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		
		int v[4];
		v[0] = 1, v[1] = 2;
		for (int i = 3; i <= n; i += 2)
		{
			int r1 = -1, r2 = -1;

			if (i + 1 <= n)
			{
				v[2] = i;
				v[3] = i + 1;
			}
			else
			{
				v[2] = i;
				v[3] = 0;
				for (int j = 1; j <= n; j++)
				{
					if (find(v, v + 4, j) == v + 4)
					{
						v[3] = j;
						break;
					}
				}
			}
			

			int res[4];
			res[0] = query(v[0], v[1], v[2]);
			res[1] = query(v[0], v[1], v[3]);
			res[2] = query(v[0], v[2], v[3]);
			res[3] = query(v[1], v[2], v[3]);

			int mx = *max_element(res, res + 4);
			if (res[0] == res[1] && res[0] == mx)
			{
				r1 = v[0];
				r2 = v[1];
			}
			else if (res[0] == res[2] && res[0] == mx)
			{
				r1 = v[0];
				r2 = v[2];
			}
			else if (res[0] == res[3] && res[0] == mx)
			{
				r1 = v[1];
				r2 = v[2];
			}
			else if (res[1] == res[2] && res[1] == mx)
			{
				r1 = v[0];
				r2 = v[3];
			}
			else if (res[1] == res[3] && res[1] == mx)
			{
				r1 = v[1];
				r2 = v[3];
			}
			else if (res[2] == res[3] && res[2] == mx)
			{
				r1 = v[2];
				r2 = v[3];
			}

			v[0] = r1;
			v[1] = r2;
		}

		cout << "! " << v[0] << ' ' << v[1] << endl;
	}
}
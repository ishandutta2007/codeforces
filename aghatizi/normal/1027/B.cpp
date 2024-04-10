#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	int q;
	cin >> n >> q;

	while(q--)
	{
		int x , y;
		cin >> x >> y;

		if((x + y) % 2)
		{
			ll res = (n * n + 1) / 2;

			res += n * ((x - 1) / 2);

			res += (y + 1) / 2;

			if(x % 2 == 0)
				res += n - (n + 1) / 2;

			cout << res << endl;
		}
		else
		{
			ll res = n * ((x - 1) / 2);

			res += (y + 1) / 2;

			if(x % 2 == 0)
				res += (n + 1) / 2;

			cout << res << endl;
		}
	}
}
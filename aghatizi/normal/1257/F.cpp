#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;
const int base[] = {4001 , 737};
const int mod[] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};

int a[maxn] , t[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	map<pair<int , int> , int> mp;
	for(int l = 0; l < (1 << 15); l++)
	{
		for(int i = 0; i < n; i++)
			t[i] = __builtin_popcount((a[i] ^ l) % (1 << 15));

		for(int i = 1; i < n; i++)
			t[i - 1] = t[i] - t[i - 1];

		int h0 = 0 , h1 = 0;
		for(int i = 0; i < n - 1; i++)
		{
			h0 = (1LL * h0 * base[0] + (t[i] + 12412)) % mod[0];
			h1 = (1LL * h1 * base[1] + (t[i] + 12412)) % mod[1];
		}

		mp[make_pair(h0 , h1)] = l;
	}

	for(int r = 0; r < (1 << 15); r++)
	{
		for(int i = 0; i < n; i++)
			t[i] = __builtin_popcount((a[i] >> 15) ^ r);

		for(int i = n - 2; i >= 0; i--)
			t[i + 1] = t[i] - t[i + 1];

		int h0 = 0 , h1 = 0;
		for(int i = 1; i < n; i++)
		{
			h0 = (1LL * h0 * base[0] + (t[i] + 12412)) % mod[0];
			h1 = (1LL * h1 * base[1] + (t[i] + 12412)) % mod[1];
		}

		if(mp.count(make_pair(h0 , h1)))
		{
			int x = (r << 15) + mp[make_pair(h0 , h1)];
			return cout << x << endl , 0;
		}
	}

	cout << -1 << endl;
}
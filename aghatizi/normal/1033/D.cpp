#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e2 + 20;
const int mod = 998244353;

map<ll , ll> mp;

ll sq2(ll a)
{
	ll l = 0 , r = 2e9;

	while(r - l > 1)
	{
		ll m = (l + r) / 2;

		if(m * m >= a)
			r = m;
		else
			l = m;
	}

	return r;
}

ll sq3(ll a)
{
	ll l = 0 , r = 2e6;

	while(r - l > 1)
	{
		ll m = (l + r) / 2;

		if(m * m * m >= a)
			r = m;
		else
			l = m;
	}

	return r;
}

ll gcd(ll a , ll b)
{
	if(!b)
		return a;

	return gcd(b , a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<ll> shits;
	for(int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;

		ll S2 = sq2(x);
		ll S3 = sq3(x);

		if(S2 * S2 == x)
		{
			if(sq2(S2) * sq2(S2) == S2)
				mp[sq2(S2)] += 4;
			else
				mp[S2] += 2;
		}
		else
		{
			if(S3 * S3 * S3 == x)
				mp[S3] += 3;
			else
				shits.pb(x);
		}
	}

	vector<ll> wt;
	for(auto x : mp)
		wt.pb(x.first);

	for(int i = 0; i < (int)shits.size(); i++)
		for(int j = i + 1; j < (int)shits.size(); j++)
		{
			ll x = shits[i] , y = shits[j];

			if(x != y && gcd(x , y) != 1)
				wt.pb(gcd(x , y));
		}

	vector<ll> tmp;
	for(auto x : shits)
	{
		bool f = 0;

		for(auto p : wt)
		{
			if(x % p == 0)
			{
				mp[p]++;
				mp[x / p]++;

				f = 1;
				break;
			}
		}

		if(!f)
			tmp.pb(x);
	}

	ll res = 1;
	for(auto x : mp)
		res = res * (x.second + 1) % mod;

	mp.clear();

	for(auto x : tmp)
		mp[x]++;

	for(auto x : mp)
		res = res * (x.second + 1) * (x.second + 1) % mod;

	cout << res << endl;
}
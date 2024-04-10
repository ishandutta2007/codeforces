#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int maxa = 15e6 + 20;

int a[maxn] , p[maxa] , t[maxa];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 2; i < maxa; i++)
		if(!p[i])
		{
			p[i] = i;
			
			for(ll j = 1LL * i * i; j < maxa; j += i)
				p[j] = i;
		}

	int n;
	cin >> n;

	int g = 0;

	bool f = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		if(!g)
			g = a[i];
		else
			g = __gcd(g , a[i]);
	}

	for(int i = 0; i < n; i++)
	{
		a[i] /= g;

		f |= (a[i] > 1);
	}

	if(!f)
		return cout << -1 << endl , 0;

	for(int i = 0; i < n; i++)
	{
		int x = a[i];

		while(x > 1)
		{
			int k = p[x];

			while(x % k == 0)
				x /= k;
			t[k]++;
		}
	}

	int res = n;
	for(int i = 2; i < maxa; i++)
		res = min(res , n - t[i]);

	cout << res << endl;
}
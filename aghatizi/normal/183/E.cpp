#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

ll a[maxn] , b[maxn];

int n , m;

inline ll f(int i)
{
	if(i * n > m)
		return -1;
	for(int j = 0; j < n; j++)
		a[j] = b[j];

	ll res = 0;
	for(int j = 0; j < n; j++)
	{
		ll tmp = 1LL * i * (j + 1) + 1LL * i * (i - 1) / 2 * n;

		if(tmp > a[j])
		{
			res = -1e18;
			break;
		}
		else
			res += tmp , a[j] -= tmp;
	}

	if(res < 0)
		return res;

	int tmp = n , last = m;
	for(int j = i * n; j >= 1; j--)
	{
		tmp--;
		if(tmp < 0)
			tmp += n;

		if(a[tmp] >= last - j)
		{
			a[tmp] -= last - j;
			res += last - j;
			last--;
		}
		else
		{
			last = j + a[tmp] - 1;
			res += a[tmp];
			a[tmp] = 0;
		}

		if(last == j - 1)
			break;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i] , b[i] = a[i];

	ll ans = 0;

	int l = 0 , r = m / n;

	while(r - l > 5)
	{
		int m1 = (l + r) / 2;

		if(f(m1) >= f(m1 + 1))
			r = m1 + 1;
		else
			l = m1;
	}

	for(int i = l; i <= r; i++)
		ans = max(ans , f(i));

	cout << ans << endl;
}
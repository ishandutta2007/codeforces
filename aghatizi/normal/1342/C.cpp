#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e4 + 20;

int s[maxn] , a , b;

ll f(ll r) // [0 , r)
{
	ll rp = (r / (a * b)) * (a * b);

	return s[0] * (rp / (a * b)) + s[0] - s[r % (a * b)];
}

void solve()
{
	int q;
	cin >> a >> b >> q;

	s[a * b] = 0;
	for(int i = a * b - 1; i >= 0; i--)
		s[i] = s[i + 1] + (((i % a) % b) != ((i % b) % a));
	
	while(q--)
	{
		ll l , r;
		cin >> l >> r;

		cout << f(r + 1) - f(l) << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}
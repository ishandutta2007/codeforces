#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int n , a , b , k;

bool check(int x)
{
	if(!x)
		return 1;

	ll tmpa = min(a , x);
	ll tmpb = min(b , x);

	ll all = (tmpa + tmpb) * (n / 2) + (n % 2) * tmpa;

	return (all / x >= k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t >> n >> a >> b >> k;

	int l = 0 , r = t + 1;

	while(r - l > 1)
	{
		int m = (l + r) / 2;

		if(check(m))
			l = m;
		else
			r = m;
	}

	cout << l << endl;
}
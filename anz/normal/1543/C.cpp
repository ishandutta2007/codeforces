#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
double p[3], v;

double ep = 1e-9;

double DFS(double a, double b, double c, int d)
{
	double ans = c / (a + b + c) * d;

	if (a > ep)
	{
		double na = max(0.0, a - v);
		double nb = b;
		double nc = c;

		double r = a - na;

		if (b > ep)
		{
			nb += r / 2;
			nc += r / 2;
		}
		else
			nc += r;

		double res = DFS(na, nb, nc, d + 1) * a / (a + b + c);
		ans += res;
	}

	if (b > ep)
	{
		double na = a;
		double nb = max(0.0, b - v);
		double nc = c;

		double r = b - nb;
		if (a > ep)
		{
			na += r / 2;
			nc += r / 2;
		}
		else
			nc += r;

		double res = DFS(na, nb, nc, d + 1) * b / (a + b + c);
		ans += res;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout.precision(12);
	cout << fixed;

	int t; cin >> t;
	while (t--)
	{
		cin >> p[0] >> p[1] >> p[2] >> v;

		double ans = DFS(p[0], p[1], p[2], 1);

		cout << ans << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
bool hasAns;

int kxor(int a, int b)
{
	if (a < b) swap(a, b);

	vector <int> va, vb;
	while (a)
	{
		va.push_back(a % k);
		a /= k;
	}

	while (b)
	{
		vb.push_back(b % k);
		b /= k;
	}

	int mul = 1;
	int res = 0;

	while (vb.size() < va.size()) vb.push_back(0);
	for (int i = 0; i < va.size(); i++)
	{
		res += (va[i] + vb[i]) % k * mul;
		mul *= k;
	}

	return res;
}

int mi(int a)
{
	vector <int> va;
	while (a)
	{
		va.push_back(a % k);
		a /= k;
	}
	for (int i = 0; i < va.size(); i++)
	{
		va[i] = (k - va[i]) % k;
	}
	int mul = 1;
	int res = 0;
	for (int i = 0; i < va.size(); i++)
	{
		res += va[i] * mul;
		mul *= k;
	}

	return res;
}

void query(int x)
{
	cout << x << endl;
	int res; cin >> res;
	if (res == -1) exit(3);
	if (res == 1) hasAns = true;
}

int res[200001];

int main()
{
	ios::sync_with_stdio(0);
	//cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		hasAns = false;
		cin >> n >> k;

		int p = 0;
		for (int i = 1; i < n; i++)
		{
			res[i] = kxor(p, i % 2 ? mi(i) : i);
			p = kxor(mi(p), res[i]);
		}

		for (int i = 0; i < n; i++)
		{
			query(res[i]);
			if (hasAns) break;
		}
	}
}
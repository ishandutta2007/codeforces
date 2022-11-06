#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;

int query(vector <int> v)
{
	cout << "?";
	for (int a : v) cout << ' ' << a;
	cout << endl;

	int res; cin >> res;
	return res;
}

int prv[101];
int nxt[101];

int ans[101];

int main()
{
	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		vector <int> v1(n, 1);
		v1[i - 1] = 2;

		int res = query(v1);
		if (res == 0) nxt[i] = -1;
		else if (res < i) nxt[i] = res, prv[res] = i;

		vector <int> v2(n, 2);
		v2[i - 1] = 1;

		res = query(v2);
		if (res == 0) prv[i] = -1;
		else if (res < i) nxt[res] = i, prv[i] = res;
	}

	int st = -1;
	for (int i = 1; i <= n; i++) if (prv[i] == -1) st = i;

	for (int i = 1; i <= n; i++)
	{
		ans[st] = i;
		st = nxt[st];
	}

	cout << "!";
	for (int i = 1; i <= n; i++) cout << ' ' << ans[i];
	cout << endl;
}
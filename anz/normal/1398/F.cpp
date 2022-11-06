#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 1000005;

int n;
string s;

int p0[N], p1[N], p2[N];
int mxLen[N];

int par[N];
int getPar(int x)
{
	if (par[x] == x) return x;
	return par[x] = getPar(par[x]);
}

void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	par[a] = b;
}

int ans[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n + 1; i++) par[i] = i;

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0') p0[i + 1] = 1;
		else if (s[i] == '1') p1[i + 1] = 1;
		else p2[i + 1] = 1;

		p0[i + 1] += p0[i];
		p1[i + 1] += p1[i];
		p2[i + 1] += p2[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n + 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			int c0 = p0[m] - p0[i - 1];
			int c1 = p1[m] - p1[i - 1];
			int c2 = p2[m] - p2[i - 1];

			if (c0 + c2 == m - i + 1 || c1 + c2 == m - i + 1)
				l = m;
			else
				r = m;
		}

		int len = l - i + 1;
		mxLen[i] = len;
	}

	mxLen[n + 1] = n + 1;

	for (int i = 1; i <= n; i++)
	{
		int ci = 1;
		while (ci <= n)
		{
			while (mxLen[ci] < i)
			{
				merge(ci, ci + 1);
				ci = getPar(ci);
			}

			if (ci == n + 1) break;
			ans[i]++;

			ci = getPar(ci + i);
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
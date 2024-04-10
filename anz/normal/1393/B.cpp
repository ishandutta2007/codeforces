#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int len[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int four = 0, two = 0;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		len[a]++;

		if (len[a] % 2 == 0) two++;
		if (len[a] % 4 == 0) four++;
	}

	int q; cin >> q;
	while (q--)
	{
		char c; int a;
		cin >> c >> a;

		if (c == '+')
		{
			len[a]++;

			if (len[a] % 2 == 0) two++;
			if (len[a] % 4 == 0) four++;
		}
		else
		{
			if (len[a] % 2 == 0) two--;
			if (len[a] % 4 == 0) four--;
			
			len[a]--;
		}

		if (four > 0 && two - 2 >= 2) cout << "YES\n";
		else cout << "NO\n";
	}
}
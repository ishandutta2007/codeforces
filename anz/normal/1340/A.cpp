#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int p[100001];
int idx[100001];
bool isUsed[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			idx[p[i]] = i;
			isUsed[i] = 0;
		}

		isUsed[n] = 1;

		bool isValid = true;
		int lastIdx = n - 1;
		for (int i = 1; i <= n; i++)
		{
			int cidx = idx[i];
			if (isUsed[lastIdx + 1] || cidx == lastIdx + 1)
			{
				lastIdx = cidx;
				isUsed[cidx] = 1;
			}
			else
			{
				isValid = false;
				break;
			}
		}

		if (isValid) cout << "Yes\n";
		else cout << "No\n";
	}
}
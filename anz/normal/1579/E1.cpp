#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		deque <int> dq;
		for (int i = 0; i < n; i++)
		{
			if (!dq.empty() && dq.front() < a[i]) dq.push_back(a[i]);
			else dq.push_front(a[i]);
		}

		for (int x : dq) cout << x << ' ';
		cout << '\n';
	}
}
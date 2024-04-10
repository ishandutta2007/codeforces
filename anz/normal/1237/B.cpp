#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];
int b[100001];

bool isFined[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		a[i] = t;
	}

	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		b[i] = t;
	}

	int ans = 0;
	int ptr = 1;
	for (int i = 1; i <= n; i++)
	{
		if (isFined[a[i]]) continue;
		if (a[i] != b[ptr])
		{
			while (a[i] != b[ptr] && ptr <= n)
			{
				isFined[b[ptr]] = 1;
				ans++;
				ptr++;
			}
		}
		ptr++;
	}
	cout << ans;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pll cor[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> cor[i].first >> cor[i].second;

	if (n % 2)
	{
		cout << "NO";
		return 0;
	}

	bool ans = true;
	for (int i = 0; i < n / 2 - 1; i++)
	{
		ll dx1 = cor[i].first - cor[i + 1].first;
		ll dy1 = cor[i].second - cor[i + 1].second;
		ll dx2 = cor[n/2+i].first - cor[n / 2 + i + 1].first;
		ll dy2 = cor[n / 2 + i].second - cor[n / 2 + i + 1].second;
		
		if (dx1 != -dx2 || dy1 != -dy2)
		{
			ans = false;
			break;
		}
	}

	if (ans) cout << "YES\n";
	else cout << "NO\n";
}
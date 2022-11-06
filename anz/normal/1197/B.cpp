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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
int a[200001];

int d[200001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		d[a[i]] = i;
	}

	int l = d[n], r = d[n];

	bool flag = true;
	for (int i = n - 1; i >= 1; i--)
	{
		if (l > 0 && a[l - 1] == i)
		{
			l--;
		}
		else if (r < n - 1 && a[r + 1] == i)
		{
			r++;
		}
		else
		{
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";
}
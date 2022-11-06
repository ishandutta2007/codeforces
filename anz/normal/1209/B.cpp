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
int isLight[101];
int a[101], b[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0') isLight[i] = 0;
		else isLight[i] = 1, ans++;
	}
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	for (int i = 1; i <= 1000; i++)
	{
		int curLight = 0;
		for (int j = 0; j < n; j++)
		{
			int l = isLight[j];
			int tog = 0;
			if (i >= b[j])
			{
				tog = (i - b[j]) / a[j] + 1;
				tog %= 2;
			}

			if (l ^ tog) curLight++;
		}

		ans = max(ans, curLight);
	}

	cout << ans;
}
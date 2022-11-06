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
int a[200001];
int ic[200001];

vector <int> stk;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (stk.empty() || a[i-1] < a[i])
		{
			stk.push_back(i);
			continue;
		}

		for (int it : stk) ic[it] = stk.size();

		ans = max(ans, (int)stk.size());
		stk.clear();
		stk.push_back(i);
	}

	for (int it : stk) ic[it] = stk.size();
	ans = max(ans, (int)stk.size());
	stk.clear();
	

	for (int i = 1; i < n - 1; i++)
	{
		if (a[i - 1] >= a[i + 1]) continue;
		if (a[i - 1] < a[i] && a[i] < a[i + 1]) continue;
		ans = max(ans, ic[i - 1] + ic[i + 1] - 1);
	}

	cout << ans;
}
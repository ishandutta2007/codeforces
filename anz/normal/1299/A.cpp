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
int a[100001];
vector<int> bt[31];
pii res[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		res[i].second = i;
		for (int j = 0; j < 31; j++)
		{
			if (a[i] & (1 << j)) bt[j].push_back(i);
		}
	}

	for (int i = 0; i < 31; i++)
	{
		if (bt[i].size() == 1)
		{
			res[bt[i][0]].first |= (1 << i);
		}
	}

	sort(res, res + n);
	for (int i = n - 1; i >= 0; i--) cout << a[res[i].second] << ' ';
}
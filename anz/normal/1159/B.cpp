#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;
int a[300001];
vector <pii> v;
int main()
{
	scanf("%d", &n);
	int minNum = 1000000007, maxNum = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		minNum = min(minNum, a[i]);
		maxNum = max(maxNum, a[i]);
		v.push_back({ a[i], i });
	}

	int ans = 1000000007;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int tmp = v[i].first;
		int ab = max(v[i].second, (n - 1) - v[i].second);
		ans = min(ans, tmp / ab);
	}

	printf("%d", ans);
}
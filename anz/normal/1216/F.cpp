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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200001;

ll n, k;
string s;

int pv[N];
ll memo[N];

vector <ll> segTree(4 * N);
void update(int ptr, int l, int r, int i, ll val)
{
	if (r < i || l > i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);
	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

ll getVal(int ptr, int l, int r, int i, int j)
{
	if (r < i || l > j) return numeric_limits<ll>::max();
	if (i <= l && r <= j) return segTree[ptr];

	ll lVal = getVal(ptr * 2, l, (l + r) / 2, i, j);
	ll rVal = getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
	return min(lVal, rVal);
}

ll dp(int i) // 0~i    
{
	ll& ret = memo[i];
	if (ret != -1) return ret;
	if (i == 0) return ret = 0;

	ret = numeric_limits<ll>::max();
	if (pv[i] == -1)
	{
		ret = i;
		ret += dp(i - 1);
		update(1, 0, n, i, ret);
		return ret;
	}

	ret = getVal(1, 0, n, max(0ll, pv[i] - k - 1), i - 1);
	ret += pv[i];
	update(1, 0, n, i, ret);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	memset(memo, -1, sizeof memo);
	cin >> n >> k >> s;

	deque <int> v;
	for (int i = 1; i <= n; i++)
	{
		if (!v.empty() && v.front() < i - k) v.pop_front();
		if (s[i - 1] == '1')
			v.push_back(i);

		if (v.empty()) pv[i] = -1;
		else pv[i] = v.front();
	}

	for (int i = 1; i <= n; i++) dp(i);
	cout << dp(n);
}
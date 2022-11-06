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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];

int solve(int s, set<int>& st)
{
	if (s < 0) return 0;
	set <int> s0, s1;
	for (auto& idx : st)
	{
		if (a[idx] & (1 << s)) s1.insert(idx);
		else s0.insert(idx);
	}

	if (s0.empty()) return solve(s - 1, s1);
	else if (s1.empty()) return solve(s - 1, s0);
	else
	{
		return min(solve(s - 1, s0), solve(s - 1, s1)) + (1 << s);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int x = 0;

	set<int> st;
	for (int i = 0; i < n; i++) st.insert(i);

	cout << solve(29, st);
}
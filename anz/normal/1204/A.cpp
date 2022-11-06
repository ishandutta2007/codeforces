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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;

	bool isAll0 = false;

	if ((int)s.size() % 2 == 1)
	{
		isAll0 = true;
		for (int i = 1; i < s.size(); i++) if (s[i] == '1') isAll0 = false;
	}
	

	if (isAll0) cout << (s.size() + 1) / 2 - 1;
	else cout << (s.size() + 1) / 2;
}
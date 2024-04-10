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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	if (s.size() == 1 && k > 0)
	{
		cout << "0";
		return 0;
	}
	if (s[0] != '1' && k > 0)
	{
		k--;
		s[0] = '1';
	}
	for (int i = 1; i < n && k > 0; i++)
	{
		if (s[i] == '0') continue;
		k--;
		s[i] = '0';
	}
	cout << s;
}
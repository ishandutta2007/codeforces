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

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+') ans++;
		else
		{
			ans--;
			if (ans < 0) ans = 0;
		}
	}
	cout << ans;
}
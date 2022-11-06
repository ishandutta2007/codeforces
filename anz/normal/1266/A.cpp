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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		bool hasZero = false;
		int sum = 0;
		int even = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int digit = s[i] - '0';
			if (digit == 0) hasZero = true;
			if (digit % 2 == 0) even++;
			sum += digit;
		}
		if (hasZero && even >= 2 && sum % 3 == 0)
			cout << "red\n";
		else
			cout << "cyan\n";
	}
}
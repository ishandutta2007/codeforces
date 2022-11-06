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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while(q--)
	{
		string s; cin >> s;
		int u = 0, d = 0, l = 0, r = 0;
		for (char c : s)
		{
			if (c == 'U') u++;
			if (c == 'D') d++;
			if (c == 'L') l++;
			if (c == 'R') r++;
		}

		int ud = min(u, d), lr = min(l, r);

		if (ud == 0) lr = min(lr, 1);
		if (lr == 0) ud = min(ud, 1);
		cout << (ud + lr) * 2 << '\n';

		for (int i = 0; i < ud; i++) cout << "U";
		for (int i = 0; i < lr; i++) cout << "L";
		for (int i = 0; i < ud; i++) cout << "D";
		for (int i = 0; i < lr; i++) cout << "R";
		cout << '\n';
	}
}
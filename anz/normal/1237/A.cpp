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
int ans[20000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> ans[i];

	bool pl = false;
	for (int i = 0; i < n; i++)
	{
		bool isMinus = false;
		int t = ans[i];
		if (t < 0)
		{
			t = -t;
			isMinus = true;
		}

		if (t % 2 == 0)
		{
			if (isMinus) cout << -(t / 2) << "\n";
			else cout << t / 2 << "\n";;
		}
		else
		{
			int res = 0;
			if (isMinus) res = -(t / 2) - 1;
			else res = (t / 2);

			if (pl) res++;
			cout << res << "\n";
			pl = !pl;
		}
	}
}
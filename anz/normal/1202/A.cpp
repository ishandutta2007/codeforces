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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;

		int b_1 = -1;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[b.size() - 1 - i] == '1')
			{
				b_1 = i;
				break;
			}
		}

		int a_1 = -1;
		for (int i = b_1; i < a.size(); i++)
		{
			if (a[a.size() - 1 - i] == '1')
			{
				a_1 = i;
				break;
			}
		}

		cout << a_1-b_1 << "\n";

	}
}
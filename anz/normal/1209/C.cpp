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

int n;
string d;

vector <int> digit[10];
int ans[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		for (int i = 0; i < 10; i++) digit[i].clear();
		cin >> n >> d;
		for (int i = 0; i < n; i++)
		{
			digit[d[i] - '0'].push_back(i);
		}

		bool isImpossible = false;
		int curIdx = -1;
		int num = 1;
		for (int i = 0; i < 10; i++)
		{
			if (digit[i].empty()) continue;
			if (digit[i].front() < curIdx)
			{
				if (num == 2)
				{
					isImpossible = true;
					break;
				}

				int nxtIdx = -1;
				for (int j = 0; j < digit[i].size(); j++)
				{
					if (digit[i][j] > curIdx) ans[digit[i][j]] = 1;
					else ans[digit[i][j]] = 2, nxtIdx = digit[i][j];
				}

				curIdx = nxtIdx;
				num = 2;
				continue;
			}

			for (int j = 0; j < digit[i].size(); j++)
			{
				ans[digit[i][j]] = num;
			}

			curIdx = digit[i].back();
		}

		if (isImpossible)
		{
			cout << "-\n";
			continue;
		}

		for (int i = 0; i < n; i++) cout << ans[i];
		cout << "\n";
	}
}